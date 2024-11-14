 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: Timer.h
 *
 * Author: Yousef ayman
 *
 *****

#include "stm32f10x.h" 
#include "DIO.h"

//###########################################
/*

PA0 -> TIM2_CH1
PA1 -> TIM2_CH2
PA2 -> TIM2_CH3
PA3 -> TIM2_CH4

PA6 -> TIM3_CH1
PA7 -> TIM3_CH2
PB0 -> TIM3_CH3
PB1 -> TIM3_CH4

PA8 -> TIM1_CH1
PA9 -> TIM1_CH2
PA10 -> TIM1_CH3
PA11 -> TIM1_CH4


void TIM1_UP_IRQHandler(){}
void TIM2_IRQHandler(){}
void TIM3_IRQHandler(){}
void TIM4_IRQHandler(){}


*/


enum timers{
	T,T1,T2,T3,T4
};

/*
    Function name         :  get_timer
    Function Returns      :  void
    Function Arguments    :  char timer
    Function Description  :  Get the timer initiallized
*/
TIM_TypeDef * get_timer(char timer);

/*
    Function name         : timer_start_micros
    Function Returns      : void
    Function Arguments    : char timer, int microS
    Function Description  : Start timer counting with micros
*/

TIM_TypeDef * timer_start_micros(char timer, int microS);

/*
    Function name         : timer_start_millis
    Function Returns      : void
    Function Arguments    : char timer, int millis
    Function Description  : Start timer counting with millis
*/

TIM_TypeDef * timer_start_millis(char timer, int millis);

/*
    Function name         : get_time_micros
    Function Returns      : int
    Function Arguments    : char timer
    Function Description  : Get the time while counting with micros
*/

int get_time_micros(char timer);

/*
    Function name         : get_time_millis
    Function Returns      : int
    Function Arguments    : char timer
    Function Description  : Get the time while counting with millis
*/

int get_time_millis(char timer);

/*
    Function name         : TDelay_Micros
    Function Returns      : void
    Function Arguments    : char timer, int microS
    Function Description  : Delay function (micros)
*/

void TDelay_Micros(char timer, int microS);

/*
    Function name         : TDelay_Millis
    Function Returns      : void
    Function Arguments    : char timer, int milliS
    Function Description  : Delay function (milliS)
*/

void TDelay_Millis(char timer, int milliS);

/*
    Function name         : TDelay_Micro
    Function Returns      : void
    Function Arguments    : int microS
    Function Description  : Delay function with timer 4 (microS)
*/
void TDelay_Micro(int microS);

/*
    Function name         : TDelay_Micro
    Function Returns      : void
    Function Arguments    : int microS
    Function Description  : Delay function with timer 4 (milliS)
*/

void TDelay_Milli(int milliS);

/*********************************************************

                     IRQ functions

**********************************************************/
/*
    Function name         : timer_irq_micro_start
    Function Returns      : void
    Function Arguments    : char timer, int microS
    Function Description  : Start timer counting with micros with interrupt
*/

void timer_irq_micro_start(char timer, int microS);

/*
    Function name         : timer_irq_millis_start
    Function Returns      : void
    Function Arguments    : char timer, int milliS
    Function Description  : Start timer counting with milliS with interrupt
*/

void timer_irq_millis_start(char timer, int milliS);

/*
    Function name         : timer_irq_Rflag
    Function Returns      : void
    Function Arguments    : char timer
    Function Description  : Read the flag after interrupt and clear it (ISR)
*/

void timer_irq_Rflag(char timer);

/*
    Function name         : timer_irq_stop
    Function Returns      : void
    Function Arguments    : char timer
    Function Description  : Disable interrupt of timer
*/
void timer_irq_stop(char timer);

/*
    Function name         : timer_stop
    Function Returns      : void
    Function Arguments    : char timer
    Function Description  : Stop timer
*/
void timer_stop(char timer);

/*********************************************************

                   Compare functions

**********************************************************/

/*
    Function name         : get_channel
    Function Returns      : void
    Function Arguments    : char port, char pin
    Function Description  : Get the channel of the timer
*/
char get_channel(char port, char pin);

/*
    Function name         : get_timer_pin
    Function Returns      : void
    Function Arguments    : char port, char pin
    Function Description  : Get the pin of the timer
*/
char get_timer_pin(char port, char pin);

/*
    Function name         : get_timer_address
    Function Returns      : void
    Function Arguments    : char port, char pin
    Function Description  : Get the timer used by this pin
*/
TIM_TypeDef * get_timer_address(char port, char pin);

/*
    Function name         : timer_compare_micro
    Function Returns      : void
    Function Arguments    : har port, char pin, int arr, int compare
    Function Description  : Upload compare value and init timer if it isn't counting with micros
*/
void timer_compare_micro(char port, char pin, int arr, int compare);

/*
    Function name         : timer_compare_milli
    Function Returns      : void
    Function Arguments    : har port, char pin, int arr, int compare
    Function Description  : Upload compare value and init timer if it isn't counting with milli
*/
void timer_compare_milli(char port, char pin, int arr, int compare);

/*********************************************************

                   PWM functions

**********************************************************/

void timer_pwm_micro(char port, char pin, int arr, int compare);
void timer_pwm_milli(char port, char pin, int arr, int compare);
