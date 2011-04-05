//{{AVR_IO_DESIGNER_INIT
	// D:\[prog]\avr_git\audio_switch\atmega48_audio_switch.aid

	//
	// Project Options - atmega48_audio_switch
	//
	// Device Name = ATmega8
	// CPU Frequency (F_CPU) = 8,0 MHz
	// IC Package = TQFP
	// Sort Pins by = Pin Number
	// Output Code File = atmega48_audio_switch.c
	// Output Header File = atmega48_audio_switch.h
	// Assume Default State = True
	// Write Unmodified Bits = True
	// Set Unused PORT Pins = Input

	//
	// PORTB variable initializations
	//
	// PORTB4 for 1: INPUT6 as Input with pullups - Reserved for pin PB4
	// PORTB5 for 1: INPUT5 as Input with pullups - Reserved for pin PB5
	PORTB = 0x30;

	//
	// PORTC variable initializations
	//
	// PORTC0 for 1: INPUT4 as Input with pullups - Reserved for pin PC0
	// PORTC1 for 1: INPUT3 as Input with pullups - Reserved for pin PC1
	// PORTC2 for 1: INPUT2 as Input with pullups - Reserved for pin PC2
	// PORTC3 for 1: INPUT1 as Input with pullups - Reserved for pin PC3
	// PORTC4 for 1: IR_INPUT as Input - 
	// PORTC5 for 1: STATUSLED as Output - Reserved for pin PC5
	PORTC = 0x0F;
	DDRC = 0x20;

	//
	// PORTD variable initializations
	//
	// PORTD1 for 1: TXD as Output - 
	// PORTD2 for 1: OUTPUT6 as Output - Reserved for pin PD2
	// PORTD3 for 1: OUTPUT5 as Output - Reserved for pin PD3
	// PORTD4 for 1: OUTPUT4 as Output - Reserved for pin PD4
	// PORTD5 for 1: OUTPUT3 as Output - Reserved for pin PD5
	// PORTD6 for 1: OUTPUT2 as Output - Reserved for pin PD6
	// PORTD7 for 1: OUTPUT1 as Output - Reserved for pin PD7
	DDRD = 0xFE;

	//
	// TIMER_COUNTER_0 -  - 
	//
	// Clock Select = clk (No prescaling)
	// Timer Overflow Interrupt Enable = Enabled
	// Counter Frequency = 31,25 kHz
	// Counter Period = 32,0 usec
	// Seconds per Count = 125,0 nsec
	// Counts per Second = 8,0 MHz
	TIMSK = 0x01;	// (1<<TOIE0)
	TCCR0 = 0x01;	// (0<<CS02)|(0<<CS01)|(1<<CS00)
//}}AVR_IO_DESIGNER_INIT
