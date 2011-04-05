/****************************************************
 * Project: 6 channel autio switch application
 * Author:  Gergo Huszty
 *
 * Published on: https://github.com/libesz
 *          and  http://libesz.digitaltrip.hu
 * 
 * This file is the header of the IR library
 *
 * Chip type        :   ATmega8 @ 8MHz with TSOP31233
 ****************************************************/

/* enable this to produde debug info on USART */
//#define DEBUG

#ifdef DEBUG
/* enable this to echo all recieved signal's data dump */
//#define ECHO_ALL_IR_SIGNAL
#endif

#ifndef IR_H
#define IR_H

//define the status LED here if you have
#define IR_LED_FEEDBACK_PORT PORTC
#define IR_LED_FEEDBACK_PIN  5

//timeouts
#define MAXTIME          250
#define MAXTIME_STARTBIT 350
#define MINTIME          10

//recieve states
#define IDLE  0
#define STARTBIT 1
#define DATABIT  2

#define LOW 0
#define HIGH 1

//temp recieve time store array size
#define IR_ARRAY_SIZE      8
#define IR_LEARNING_TRY    10
#define IR_LEARNING_SAMPLE 3

#define LEARNING_DONE         0
#define LEARNING_NOT_COMPLETE 1
#define LEARNING_FAILED       2

//stored data in eeprom
#define IR_FIRST_DATA_ADDRESS 10
#define IR_STORED_DATA_AMOUNT 6

extern void ir_echo_times( void );
extern void ir_push_time( unsigned char );
extern void ir_handle_timer( void );
extern void ir_handle_input( unsigned char );
extern void ir_delete_buffer( void );
extern void ir_delete_learning_samples( void );
extern void ir_start_learning( unsigned char );
extern void ir_cancel_learning( void );
extern void ir_save_current( void );
extern void ir_search_current( void );
extern unsigned char ir_is_recieve_ready( void );
extern unsigned char ir_get_learning_state( void );

#endif
