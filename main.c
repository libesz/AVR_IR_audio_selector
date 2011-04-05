/****************************************************
 * Project: 6 channel autio switch application
 * Author:  Gergo Huszty
 *
 * Published on: https://github.com/libesz
 *          and  http://libesz.digitaltrip.hu
 * 
 * You can turn on the debug feature in the ir.h file
 *
 * Chip type        :   ATmega8 @ 8MHz with TSOP31233
 ****************************************************/
 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include "audio_switch.h"
#include "ir.h"
#ifdef DEBUG
#include "usart.h"
#endif

//EEPROM addresses
#define CONFIG_ADDRESS (unsigned char *)0
#define LAST_STATE_ADDRESS (unsigned char *)1
extern unsigned char init_eeprom( void );

unsigned char read_input( void );
void set_output( unsigned char );

#ifdef DEBUG
ISR(USART_RXC_vect)
{
   //dummy USART recieve interrupt
   unsigned char usart_rec_byte=0;
   usart_rec_byte = UDR;
   if( usart_rec_byte == '\r' )
   {
      usart_nl();
   }
   else
   {
      usart_putc(usart_rec_byte);
   }

}
#endif

// timer overflow for more proper time measure
ISR (TIMER0_OVF_vect)
{
   ir_handle_timer();
}

int main( void )
{
//preparing the IO
#include "audio_switch.c"

#ifdef DEBUG
   usart_init();
   usart_puts_P( "Hello World!" );
   usart_nl();
#endif
   sei();
   unsigned char last_input = 0, next_input = 0;

#ifdef DEBUG
#define INPUT_TYPE_IR     0
#define INPUT_TYPE_BUTTON 1
   unsigned char input_type = INPUT_TYPE_IR;
#endif
   
   if( !INPUT1 )
   {
      for( unsigned char i = 1; i <= IR_STORED_DATA_AMOUNT; i++ )
      {
         ir_start_learning( i );
         set_output( i );

#ifdef DEBUG
         usart_puts_P( "learning IR input " );
         usart_puti( i );
         usart_puts_P( ": " );
#endif
         while( ir_get_learning_state() == LEARNING_NOT_COMPLETE )
         {
            ir_handle_input( IR_INPUT );
         }
         if( ir_get_learning_state() == LEARNING_FAILED ) break;
      }
   }

#ifdef DEBUG
   usart_puts_P( "going to normal operation" );
   usart_nl();
#endif

   next_input = init_eeprom();
   set_output( next_input );
   STATUSLED = 1;
   
   while(1)
   {
      next_input = read_input();
      if( !next_input )
      {
         next_input = ir_is_recieve_ready();
         
#ifdef DEBUG
         if( next_input )
         {
            input_type = INPUT_TYPE_IR;
         }
#endif
      }
#ifdef DEBUG
      else
      {
         if( next_input )
         {
            input_type = INPUT_TYPE_BUTTON;
         }
      }
#endif
      if( ( last_input != next_input ) && next_input )
      {
#ifdef DEBUG
         if( input_type == INPUT_TYPE_BUTTON )
         {
            usart_puts_P( "recieved button input: ");
         }
         else
         {
            usart_puts_P( "recieved IR input: ");
         }
         usart_puti( next_input );
         usart_nl();
#endif

         eeprom_write_byte( LAST_STATE_ADDRESS, next_input );
         set_output( next_input );
         last_input = next_input;
      }
      ir_handle_input( IR_INPUT );
   }
}

unsigned char read_input( void )
{
   if( !INPUT1 ) return 1;
   else if( !INPUT2 ) return 2;
   else if( !INPUT3 ) return 3;
   else if( !INPUT4 ) return 4;
   else if( !INPUT5 ) return 5;
   else if( !INPUT6 ) return 6;
   return 0;
}

void set_output( unsigned char new_value )
{
   OUTPUT1 = 0;
   OUTPUT2 = 0;
   OUTPUT3 = 0;
   OUTPUT4 = 0;
   OUTPUT5 = 0;
   OUTPUT6 = 0;
   
   switch( new_value )
   {
      case 1: OUTPUT1 = 1;
         break;
      case 2: OUTPUT2 = 1;
         break;
      case 3: OUTPUT3 = 1;
         break;
      case 4: OUTPUT4 = 1;
         break;
      case 5: OUTPUT5 = 1;
         break;
      case 6: OUTPUT6 = 1;
         break;
   }
}


unsigned char init_eeprom( void )
{
   //the eeprom content is checked by this byte, if it is not 01010101, the eeprom is in the initial state (for example after programming)
   if( 0x55 == eeprom_read_byte( CONFIG_ADDRESS ) )
   {
      return eeprom_read_byte( LAST_STATE_ADDRESS );
   }
   else
   {
      eeprom_write_byte( CONFIG_ADDRESS, 0x55 );
      eeprom_write_byte( LAST_STATE_ADDRESS, 1 );
      return 1;
   }
}

 