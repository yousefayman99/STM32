 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: DIO.h
 *
 * Author: Yousef ayman
 *
 *******************************************************************************/
 


#define RCC_APBENR       (*((volatile unsigned long *) 0x40021018))

#define GPIO_A       		 (*((volatile unsigned long *) 0x40010800))
#define GPIO_B       		 (*((volatile unsigned long *) 0x40010C00))
#define GPIO_C       		 (*((volatile unsigned long *) 0x40011000))



#define PA          1           
#define PB          2           
#define PC          3          

#define HIGH       1
#define LOW        0

#define  IN        0
#define  OUT10     1
#define  OUT2      2
#define  OUT50     3


#define I_AN 0
#define I_F  1
#define I_PP 2

#define O_GP_PP 0
#define O_GP_OD 1
#define O_AF_PP 2
#define O_AF_OD 3


/*
    Function name         :  DIO_set_pin_dir
    Function Returns      :  void
    Function Arguments    :  unsigned short port, unsigned short pin, unsigned short direction, unsigned short speed.
    Function Description  :  Set the Pin direction 'I/P'(@direction=0) or 'O/P'(@direction=1).
*/

void DIO_set_pin_dir(unsigned short PORT,unsigned short PIN,unsigned short DIR,unsigned short OPT);

/*
    Function name         :  DIO_read_pin
    Function Returns      :  unsigned char
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Read the value from 'I/P' pin
*/

int DIO_read_pin(unsigned short PORT,unsigned short pin);

/*
    Function name         :  DIO_write_pin
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin, unsigned char value
    Function Description  :  Set the 'O/P' pin as 'HIGH'(@value=1) or 'LOW'(@value=0)
*/

void DIO_write_pin(unsigned short PORT,unsigned short pin, unsigned short STATUS);

/*
    Function name         :  DIO_toogle_pin_oput
    Function Returns      :  void
    Function Arguments    :  unsigned char port, unsigned char pin
    Function Description  :  Toogle the 'O/P' pin value 'HIGH' or 'LOW'
*/

void DIO_toogle(unsigned short Port,unsigned short pin);

/*
    Function name         :  B_init
    Function Returns      :  void
    Function Arguments    :  unsigned short state.
    Function Description  :  init pin13 (built in led)
*/

void B_init(void);

/*
    Function name         :  BLED
    Function Returns      :  void
    Function Arguments    :  unsigned short state.
    Function Description  :  Write to the pin13 (built in led)
*/

void BLED(unsigned short state);

/*
    Function name         :  Digital_Input
    Function Returns      :  void
    Function Arguments    :  unsigned short PORT,unsigned short PIN.
    Function Description  :  init pin to input state.
*/

void Digital_Input(unsigned short PORT,unsigned short PIN);

/*
    Function name         :  Digital_Input
    Function Returns      :  void
    Function Arguments    :  unsigned short PORT,unsigned short PIN.
    Function Description  :  init pin to output state.
*/

void Digital_Output(unsigned short PORT,unsigned short PIN);

void PINc(unsigned short pin, unsigned short STATUS);
