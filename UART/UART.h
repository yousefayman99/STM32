 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART.h
 *
 * Author: Yousef ayman
 *
 *******************************************************************************/

#include "stm32f10x.h"  
#include "DIO.h" 
#include "systick_time.h"


char USART_1_msg[250];
unsigned short USART_1_cnt = 0;
unsigned short USART_1_sig = 0;
unsigned short USART_1_bdg = 0;

char USART_2_msg[250];
unsigned short USART_2_cnt = 0;
unsigned short USART_2_sig = 0;
unsigned short USART_2_bdg = 0;

char USART_3_msg[250];
unsigned short USART_3_cnt = 0;
unsigned short USART_3_sig = 0;
unsigned short USART_3_bdg = 0;

unsigned long USART_BRR(unsigned short usart, unsigned long BR);
/*
    Function name         :  UART_init
    Function Returns      :  void
    Function Arguments    :  unsigned short usart, unsigned long BR
    Function Description  :  Initialize the USART communication.
*/
void UART_init(unsigned short usart, unsigned long BR);

/*
    Function name         :  UART_receive
    Function Returns      :  char
    Function Arguments    :  unsigned short uart
    Function Description  :  Receive data by UART.
*/
char UART_receive(unsigned short uart);

/*
    Function name         :  UART_send
    Function Returns      :  void
    Function Arguments    :  unsigned short uart,char c
    Function Description  :  Send data by UART.
*/
void UART_send_char(unsigned short uart,char c);

/*
    Function name         :  UART_ISR
    Function Returns      :  void
    Function Arguments    : unsigned short uart,unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[]
    Function Description  :  recive data by interrupt of UART.
*/

void UART_ISR(unsigned short uart,unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[]);

/*
    Function name         :  UART_send
    Function Returns      :  void
    Function Arguments    :  unsigned short uart,char str[])
    Function Description  :  Send multiple data by UART.
*/

void UART_SEND_data(unsigned short uart, char str[]);
//void str_empty(char str[]);