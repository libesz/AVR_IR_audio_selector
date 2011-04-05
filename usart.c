/****************************************************
 * Project: 6 channel autio switch application
 * Author:  Gergo Huszty
 *
 * Published on: https://github.com/libesz
 *          and  http://libesz.digitaltrip.hu
 * 
 * You can turn on the debug feature in the ir.h file
 *
 * This file is the code of the lightweight 
 * USART library, used in case of debugging
 *
 * Chip type        :   ATmega8 @ 8MHz with TSOP31233
 ****************************************************/

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "usart.h"


void usart_init( void )
{
   UCSRB |= (1 << RXEN) | (1 << TXEN);
   UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

   UBRRL = BAUD_PRESCALE;
   UBRRH = (BAUD_PRESCALE >> 8);
   UCSRB |= (1 << RXCIE);
}

void usart_putc( unsigned char c )
{
      while ((UCSRA & (1 << UDRE)) == 0);
      UDR = c;
}

void usart_puts ( unsigned char *s)
{
   while (*s)
   {
      usart_putc(*s);
      s++;
   }
}

void usart_nl( void )
{
   usart_puts_P("\r\n");
}

void usart_puts_p(const char *progmem_s )
{
    register char c;
    
    while ( (c = pgm_read_byte(progmem_s++)) ) 
      usart_putc(c);

}

void usart_puti( const int val )
{
    char buffer[sizeof(int)*8+1];
    
    usart_puts( itoa(val, buffer, 10) );

}
