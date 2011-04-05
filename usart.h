/****************************************************
 * Project: 6 channel autio switch application
 * Author:  Gergo Huszty
 *
 * Published on: https://github.com/libesz
 *          and  http://libesz.digitaltrip.hu
 * 
 * You can turn on the debug feature in the ir.h file
 *
 * This file is the header of the lightweight 
 * USART library, used in case of debugging
 *
 * Chip type        :   ATmega8 @ 8MHz with TSOP31233
 ****************************************************/

#ifndef UART_H
#define UART_H

#define USART_BAUDRATE 38400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define usart_puts_P(__s) usart_puts_p(P(__s))
#define P(s) ({static const char c[] __attribute__ ((progmem)) = s;c;})


extern void usart_init( void );

extern void usart_putc( unsigned char c );

extern void usart_puts ( unsigned char *s);

extern void usart_nl( void );

extern void usart_puts_p(const char *progmem_s );

extern void usart_puti( const int val );

#endif // UART_H 
