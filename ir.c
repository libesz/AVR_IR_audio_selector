/****************************************************
 * Project: 6 channel autio switch application
 * Author:  Gergo Huszty
 *
 * Published on: https://github.com/libesz
 *          and  http://libesz.digitaltrip.hu
 * 
 * You can turn on the debug feature in the ir.h file
 *
 * This file is the code of the IR library
 *
 * Chip type        :   ATmega8 @ 8MHz with TSOP31233
 ****************************************************/
 
#include <avr/eeprom.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "ir.h"
#ifdef DEBUG
#include "usart.h"
#endif

volatile unsigned char ir_signal[IR_ARRAY_SIZE]; //stores the current signal
volatile unsigned char ir_signal_pointer = 0;    //points to the last digit of the signal array
volatile unsigned char ir_signal_length = 0;     //the amount of the recieved signal bits
volatile unsigned char ir_signal_bitshift = 0;   //points into the actual signal byte's actual bit
volatile unsigned char ir_low_signal_time = 0;   //the reference time for the signal decoding, measured after the startbit
volatile unsigned int ir_startbit_time = 0;
volatile unsigned int ir_measured_time=0;        //the actually counted time period
volatile unsigned char ir_recieve_complete = 0;  //indicates if the signal is completely recieved (and timeout reached after it)
volatile unsigned char ir_recieve_state = IDLE;  
volatile unsigned char ir_last_input_state = LOW;
volatile unsigned char ir_learning_this = 0;     //the number of the currently learned signal
volatile unsigned char ir_learning_samples[IR_LEARNING_SAMPLE][IR_ARRAY_SIZE];
volatile unsigned char ir_learning_pointer = 0;  //points to the sample table
volatile unsigned char ir_learning_try = 0;      //stores the amount of tryes while learning
volatile unsigned char ir_learning_state = LEARNING_NOT_COMPLETE;
volatile unsigned char ir_input_match = 0;


void ir_push_time( unsigned char time )
{
   if( ir_signal_pointer < IR_ARRAY_SIZE )
   {
      //shift the bits left
      ir_signal[ ir_signal_pointer ] <<= 1;
      if( ++ir_signal_bitshift == 8 )
      {
         ir_signal_bitshift = 0;
         ir_signal_pointer++;
      }
      if( ( ( time ) / ( ir_low_signal_time ) ) > 2 )
      {
         //the bit was 1
         ir_signal[ ir_signal_pointer ]++;
      }
      ir_signal_length++;
   }
}

#ifdef ECHO_ALL_IR_SIGNAL
void ir_echo_times( void )
{
   unsigned char temp_index = 0;
   
   usart_puts_P( "Startbit time: " );
   usart_puti( ir_startbit_time );
   usart_nl();
   usart_puts_P( "Low signal length: " );
   usart_puti( ir_low_signal_time );
   usart_nl();
   usart_puts_P( "Data length: " );
   usart_puti( ir_signal_length );
   usart_nl();
   //usart_puts_P();
   while( temp_index <= ir_signal_pointer )
   {
      //usart_puti( ( ir_signal[ temp_index ] - ir_signal[ 0 ] + 10 ) / ir_signal[ 0 ] );
      //usart_puti( ir_signal[ temp_index ] - ir_signal[ 0 ] );
      usart_puti( ir_signal[ temp_index ] );
      //usart_puti( ( ir_signal[ temp_index ] ) / ( ir_signal[ 0 ] - 2 ) ) ;
      usart_putc(' ');
      temp_index++;
   }
   usart_nl();
}
#endif

void ir_delete_buffer( void )
{
   memset( &ir_signal, 0, IR_ARRAY_SIZE );

   ir_recieve_complete = 0;
   ir_signal_pointer = 0;
   ir_signal_bitshift = 0;
   ir_signal_length = 0;
   ir_input_match = 0;
}

void ir_delete_learning_samples( void )
{
   memset( ir_learning_samples, 0, IR_LEARNING_SAMPLE * IR_ARRAY_SIZE );
}

void ir_handle_timer( void )
{
   //timeout not reached
   if( ( ir_measured_time < MAXTIME ) || ( ( ir_recieve_state == STARTBIT ) && ( ir_measured_time < MAXTIME_STARTBIT ) ) )
   {
      //delete the last recieved data
      if( ir_recieve_complete )
      {
         ir_delete_buffer();
      }
      ir_measured_time++;
   }
   //timeout reached and counting is not in idle state, so we got a complete IR signal
   else if( ir_recieve_state > IDLE )
   {
      IR_LED_FEEDBACK_PORT |= 1<<IR_LED_FEEDBACK_PIN;

      ir_recieve_state = IDLE;
      ir_recieve_complete = 1;
      if( ir_learning_this ) //if actually learning something
      {
         unsigned char temp_index = 0, valid = 1;
         while( temp_index < IR_ARRAY_SIZE ) //copy the recieved signal to to samples table
         {
            ir_learning_samples[ir_learning_pointer][ temp_index ] =  ir_signal[ temp_index ];
            temp_index++;
         }
         if( ++ir_learning_pointer == IR_LEARNING_SAMPLE ) ir_learning_pointer = 0; //round the pointer to the first array element
         
         for( unsigned char i = 1; i < IR_LEARNING_SAMPLE; i++ )
         {
            temp_index = 0;
            while( temp_index < IR_ARRAY_SIZE )
            {
               if( ir_learning_samples[0][temp_index] != ir_learning_samples[i][temp_index] )
               {
                  valid = 0;
                  break;
               }
               temp_index++;
            }
            if( !valid ) break;
         }
         if( valid )
         {
            ir_save_current();
            ir_learning_state = LEARNING_DONE;
            ir_learning_this = 0;
            ir_learning_try = 0;
#ifdef DEBUG
            usart_puts_P("saved");
            usart_nl();
#endif
            ir_delete_learning_samples();
         }
         else
         {
            if( ++ir_learning_try == IR_LEARNING_TRY )
            {
               ir_learning_this = 0;
               ir_learning_state = LEARNING_FAILED;
               ir_learning_try = 0;
#ifdef DEBUG
               usart_puts_P("failed");
               usart_nl();
#endif
               ir_delete_learning_samples();
            }
         }
      }
      else
      {
         ir_search_current();
      }
#ifdef ECHO_ALL_IR_SIGNAL
      ir_echo_times();
#endif
   }
}

void ir_save_current( void )
{
   unsigned char *write_pointer = ( unsigned char * ) ( IR_FIRST_DATA_ADDRESS + ( ( ir_learning_this - 1 ) * ( IR_ARRAY_SIZE + 2 ) ) );
   eeprom_write_byte( write_pointer, ir_low_signal_time ); //for future purpose (transmitting the learned stuff)
   eeprom_write_byte( ++write_pointer, ir_signal_length ); //for future purpose
   for( unsigned char i = 0; i < IR_ARRAY_SIZE; i++ )
   {
      eeprom_write_byte( ++write_pointer, ir_signal[i] );
   }
}

void ir_search_current( void )
{
   unsigned char valid = 1, *read_pointer = 0;
   for( unsigned char i = 0; i < IR_STORED_DATA_AMOUNT; i++ )
   {
      read_pointer = ( unsigned char * ) IR_FIRST_DATA_ADDRESS + i * ( IR_ARRAY_SIZE + 2 ) + 2;
      for( unsigned char j = 0; j < IR_ARRAY_SIZE; j++ )
      {
         if( ir_signal[j] != eeprom_read_byte( read_pointer++ ) )
         {
            valid = 0;
            break;
         }
      }
      if( valid )
      {
         ir_input_match = i + 1;
         break;
      }
      else
      {
         valid = 1;
      }
   }
#ifdef DEBUG
   if( !ir_input_match )
   {
      usart_puts_P( "no match" );
      usart_nl();
   }
#endif
}

void ir_handle_input( unsigned char input_state )
{
   if( ( !input_state ) && ( ir_last_input_state == HIGH ) )
   {
      IR_LED_FEEDBACK_PORT &= ~(1<<IR_LED_FEEDBACK_PIN);

      ir_last_input_state = LOW;
      if( ir_recieve_state == IDLE )
      {
         ir_recieve_state = STARTBIT;
         ir_measured_time = 0;
      }
      else if( ir_recieve_state == STARTBIT )
      {
         ir_startbit_time = ir_measured_time;
         ir_recieve_state = DATABIT;
         ir_measured_time = 0;
      }
      else if( ir_recieve_state == DATABIT )
      {
         ir_push_time( ir_measured_time );
         ir_measured_time = 0;
      }
   }
   if( ( input_state ) && ( ir_last_input_state == LOW ) )
   {
      ir_last_input_state = HIGH;
      //save the low part of the signal to calculate with it later
      if( ( ir_recieve_state == DATABIT ) && ( !ir_signal_pointer ) )
      {
         ir_low_signal_time = ir_measured_time - 2 ;
      }
   }
}

void ir_start_learning( unsigned char stored_place )
{
   if( stored_place <= IR_STORED_DATA_AMOUNT )
   {
      ir_learning_this = stored_place;
      ir_learning_state = LEARNING_NOT_COMPLETE;
   }
   else
   {
      ir_learning_state = LEARNING_FAILED;
   }
}

void ir_cancel_learning( void )
{
   ir_learning_this = 0;
}

unsigned char ir_is_recieve_ready( void )
{
   if( ir_recieve_complete )
   {
      unsigned char return_value = ir_input_match;
      if( return_value )
      {
         ir_input_match = 0;
      }
      return return_value;
   }
   else
   {
      return 0;
   }
}

unsigned char ir_get_learning_state( void )
{
   return ir_learning_state;
}

