//{{AVR_IO_DESIGNER_HDR
// D:\[prog]\avr_git\audio_switch\atmega48_audio_switch.aid

//
// PORTB variable definitions
//
typedef struct
{
	unsigned char	_Unused0         : 1;	// 
	unsigned char	_Unused1         : 1;	// 
	unsigned char	_Unused2         : 1;	// 
	unsigned char	_Unused3         : 1;	// 
	unsigned char	_INPUT6          : 1;	// Reserved for pin PB4
	unsigned char	_INPUT5          : 1;	// Reserved for pin PB5
	unsigned char	_Unused6         : 1;	// 
	unsigned char	_Unused7         : 1;	// 
} PORTB_STRUCT;

// PORTB4 for 1: INPUT6 as Input with pullups - Reserved for pin PB4
#define	INPUT6_PORT             ((volatile PORTB_STRUCT*)&PORTB)        // PORT register
#define	INPUT6_PIN              ((volatile PORTB_STRUCT*)&PINB)         // PIN register
#define	INPUT6_DDR              ((volatile PORTB_STRUCT*)&DDRB)         // DDR register
#define	INPUT6                  INPUT6_PIN->_INPUT6                     // input
#define	INPUT6_PULLUP           INPUT6_PORT->_INPUT6                    // pullup control
#define	INPUT6_DIR              INPUT6_DDR->_INPUT6                     // direction control
#define	INPUT6_MASK             0x10                                    // mask
#define	INPUT6_SHIFT            0x04                                    // shift count

// PORTB5 for 1: INPUT5 as Input with pullups - Reserved for pin PB5
#define	INPUT5_PORT             ((volatile PORTB_STRUCT*)&PORTB)        // PORT register
#define	INPUT5_PIN              ((volatile PORTB_STRUCT*)&PINB)         // PIN register
#define	INPUT5_DDR              ((volatile PORTB_STRUCT*)&DDRB)         // DDR register
#define	INPUT5                  INPUT5_PIN->_INPUT5                     // input
#define	INPUT5_PULLUP           INPUT5_PORT->_INPUT5                    // pullup control
#define	INPUT5_DIR              INPUT5_DDR->_INPUT5                     // direction control
#define	INPUT5_MASK             0x20                                    // mask
#define	INPUT5_SHIFT            0x05                                    // shift count

//
// PORTC variable definitions
//
typedef struct
{
	unsigned char	_INPUT4          : 1;	// Reserved for pin PC0
	unsigned char	_INPUT3          : 1;	// Reserved for pin PC1
	unsigned char	_INPUT2          : 1;	// Reserved for pin PC2
	unsigned char	_INPUT1          : 1;	// Reserved for pin PC3
	unsigned char	_IR_INPUT        : 1;	// 
	unsigned char	_STATUSLED       : 1;	// Reserved for pin PC5
	unsigned char	_Unused6         : 1;	// 
} PORTC_STRUCT;

// PORTC0 for 1: INPUT4 as Input with pullups - Reserved for pin PC0
#define	INPUT4_PORT             ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	INPUT4_PIN              ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	INPUT4_DDR              ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	INPUT4                  INPUT4_PIN->_INPUT4                     // input
#define	INPUT4_PULLUP           INPUT4_PORT->_INPUT4                    // pullup control
#define	INPUT4_DIR              INPUT4_DDR->_INPUT4                     // direction control
#define	INPUT4_MASK             0x01                                    // mask
#define	INPUT4_SHIFT            0x00                                    // shift count

// PORTC1 for 1: INPUT3 as Input with pullups - Reserved for pin PC1
#define	INPUT3_PORT             ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	INPUT3_PIN              ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	INPUT3_DDR              ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	INPUT3                  INPUT3_PIN->_INPUT3                     // input
#define	INPUT3_PULLUP           INPUT3_PORT->_INPUT3                    // pullup control
#define	INPUT3_DIR              INPUT3_DDR->_INPUT3                     // direction control
#define	INPUT3_MASK             0x02                                    // mask
#define	INPUT3_SHIFT            0x01                                    // shift count

// PORTC2 for 1: INPUT2 as Input with pullups - Reserved for pin PC2
#define	INPUT2_PORT             ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	INPUT2_PIN              ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	INPUT2_DDR              ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	INPUT2                  INPUT2_PIN->_INPUT2                     // input
#define	INPUT2_PULLUP           INPUT2_PORT->_INPUT2                    // pullup control
#define	INPUT2_DIR              INPUT2_DDR->_INPUT2                     // direction control
#define	INPUT2_MASK             0x04                                    // mask
#define	INPUT2_SHIFT            0x02                                    // shift count

// PORTC3 for 1: INPUT1 as Input with pullups - Reserved for pin PC3
#define	INPUT1_PORT             ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	INPUT1_PIN              ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	INPUT1_DDR              ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	INPUT1                  INPUT1_PIN->_INPUT1                     // input
#define	INPUT1_PULLUP           INPUT1_PORT->_INPUT1                    // pullup control
#define	INPUT1_DIR              INPUT1_DDR->_INPUT1                     // direction control
#define	INPUT1_MASK             0x08                                    // mask
#define	INPUT1_SHIFT            0x03                                    // shift count

// PORTC4 for 1: IR_INPUT as Input - 
#define	IR_INPUT_PORT           ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	IR_INPUT_PIN            ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	IR_INPUT_DDR            ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	IR_INPUT                IR_INPUT_PIN->_IR_INPUT                 // input
#define	IR_INPUT_PULLUP         IR_INPUT_PORT->_IR_INPUT                // pullup control
#define	IR_INPUT_DIR            IR_INPUT_DDR->_IR_INPUT                 // direction control
#define	IR_INPUT_MASK           0x10                                    // mask
#define	IR_INPUT_SHIFT          0x04                                    // shift count

// PORTC5 for 1: STATUSLED as Output - Reserved for pin PC5
#define	STATUSLED_PORT          ((volatile PORTC_STRUCT*)&PORTC)        // PORT register
#define	STATUSLED_PIN           ((volatile PORTC_STRUCT*)&PINC)         // PIN register
#define	STATUSLED_DDR           ((volatile PORTC_STRUCT*)&DDRC)         // DDR register
#define	STATUSLED               STATUSLED_PORT->_STATUSLED              // output
#define	STATUSLED_TOGGLE        STATUSLED_PIN->_STATUSLED               // output toggle
#define	STATUSLED_DIR           STATUSLED_DDR->_STATUSLED               // direction control
#define	STATUSLED_MASK          0x20                                    // mask
#define	STATUSLED_SHIFT         0x05                                    // shift count

//
// PORTD variable definitions
//
typedef struct
{
	unsigned char	_Unused0         : 1;	// 
	unsigned char	_TXD             : 1;	// 
	unsigned char	_OUTPUT6         : 1;	// Reserved for pin PD2
	unsigned char	_OUTPUT5         : 1;	// Reserved for pin PD3
	unsigned char	_OUTPUT4         : 1;	// Reserved for pin PD4
	unsigned char	_OUTPUT3         : 1;	// Reserved for pin PD5
	unsigned char	_OUTPUT2         : 1;	// Reserved for pin PD6
	unsigned char	_OUTPUT1         : 1;	// Reserved for pin PD7
} PORTD_STRUCT;

// PORTD1 for 1: TXD as Output - 
#define	TXD_PORT                ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	TXD_PIN                 ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	TXD_DDR                 ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	TXD                     TXD_PORT->_TXD                          // output
#define	TXD_TOGGLE              TXD_PIN->_TXD                           // output toggle
#define	TXD_DIR                 TXD_DDR->_TXD                           // direction control
#define	TXD_MASK                0x02                                    // mask
#define	TXD_SHIFT               0x01                                    // shift count

// PORTD2 for 1: OUTPUT6 as Output - Reserved for pin PD2
#define	OUTPUT6_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT6_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT6_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT6                 OUTPUT6_PORT->_OUTPUT6                  // output
#define	OUTPUT6_TOGGLE          OUTPUT6_PIN->_OUTPUT6                   // output toggle
#define	OUTPUT6_DIR             OUTPUT6_DDR->_OUTPUT6                   // direction control
#define	OUTPUT6_MASK            0x04                                    // mask
#define	OUTPUT6_SHIFT           0x02                                    // shift count

// PORTD3 for 1: OUTPUT5 as Output - Reserved for pin PD3
#define	OUTPUT5_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT5_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT5_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT5                 OUTPUT5_PORT->_OUTPUT5                  // output
#define	OUTPUT5_TOGGLE          OUTPUT5_PIN->_OUTPUT5                   // output toggle
#define	OUTPUT5_DIR             OUTPUT5_DDR->_OUTPUT5                   // direction control
#define	OUTPUT5_MASK            0x08                                    // mask
#define	OUTPUT5_SHIFT           0x03                                    // shift count

// PORTD4 for 1: OUTPUT4 as Output - Reserved for pin PD4
#define	OUTPUT4_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT4_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT4_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT4                 OUTPUT4_PORT->_OUTPUT4                  // output
#define	OUTPUT4_TOGGLE          OUTPUT4_PIN->_OUTPUT4                   // output toggle
#define	OUTPUT4_DIR             OUTPUT4_DDR->_OUTPUT4                   // direction control
#define	OUTPUT4_MASK            0x10                                    // mask
#define	OUTPUT4_SHIFT           0x04                                    // shift count

// PORTD5 for 1: OUTPUT3 as Output - Reserved for pin PD5
#define	OUTPUT3_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT3_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT3_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT3                 OUTPUT3_PORT->_OUTPUT3                  // output
#define	OUTPUT3_TOGGLE          OUTPUT3_PIN->_OUTPUT3                   // output toggle
#define	OUTPUT3_DIR             OUTPUT3_DDR->_OUTPUT3                   // direction control
#define	OUTPUT3_MASK            0x20                                    // mask
#define	OUTPUT3_SHIFT           0x05                                    // shift count

// PORTD6 for 1: OUTPUT2 as Output - Reserved for pin PD6
#define	OUTPUT2_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT2_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT2_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT2                 OUTPUT2_PORT->_OUTPUT2                  // output
#define	OUTPUT2_TOGGLE          OUTPUT2_PIN->_OUTPUT2                   // output toggle
#define	OUTPUT2_DIR             OUTPUT2_DDR->_OUTPUT2                   // direction control
#define	OUTPUT2_MASK            0x40                                    // mask
#define	OUTPUT2_SHIFT           0x06                                    // shift count

// PORTD7 for 1: OUTPUT1 as Output - Reserved for pin PD7
#define	OUTPUT1_PORT            ((volatile PORTD_STRUCT*)&PORTD)        // PORT register
#define	OUTPUT1_PIN             ((volatile PORTD_STRUCT*)&PIND)         // PIN register
#define	OUTPUT1_DDR             ((volatile PORTD_STRUCT*)&DDRD)         // DDR register
#define	OUTPUT1                 OUTPUT1_PORT->_OUTPUT1                  // output
#define	OUTPUT1_TOGGLE          OUTPUT1_PIN->_OUTPUT1                   // output toggle
#define	OUTPUT1_DIR             OUTPUT1_DDR->_OUTPUT1                   // direction control
#define	OUTPUT1_MASK            0x80                                    // mask
#define	OUTPUT1_SHIFT           0x07                                    // shift count

// TIMER_COUNTER_0 -  - 
#define	TIMER_COUNTER_0_Divisor	1
#define	TIMER_COUNTER_0_CountsPerSecond	8000000
#define	TIMER_COUNTER_0_nsPerCount	125             // (125)
#define	TIMER_COUNTER_0_usPeriod	32              // (32)
#define	TIMER_COUNTER_0_nsPeriod	32000           // (32000)
//}}AVR_IO_DESIGNER_HDR
