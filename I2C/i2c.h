 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.h
 *
 * Author: Yousef ayman
 *
 *******************************************************************************/ 




#include "stm32f10x.h"
#include "DIO.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave
#define BUFFER_LENGTH    32
// #define bool	bool
// #define false	false
// #define true	true
#define i2c_FM 0x2d
#define i2c_SM 0xB4
#define ACK 0
#define NACK 1


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
    Function name         :  TWI_init
    Function Returns      :  void
    Function Arguments    :  char i2c,unsigned short speed_mode
    Function Description  :  init the i2c.
*/

void TWI_init(char i2c,unsigned short speed_mode);

/*
    Function name         :  TWI_start
    Function Returns      :  void
    Function Arguments    :  char i2c
    Function Description  : Send start bit to i2c .
*/
void TWI_start(char i2c);

/*
    Function name         :  TWI_write_multiple_data
    Function Returns      :  void
    Function Arguments    :  char i2c, char address,char data[]
    Function Description  :  Write multiple data to i2c .
*/

void TWI_write_multiple_data(char i2c, char address,char data[]);

/*
    Function name         :  TWI_write_address
    Function Returns      :  void
    Function Arguments    :  char i2c, char address,char RW
    Function Description  :  Write the adress in i2c.
*/

char TWI_write_address(char i2c, char address,char RW);

/*
    Function name         :  TWI_write
    Function Returns      :  void
    Function Arguments    :  char i2c,char data
    Function Description  :  Write i byte of data to i2c.
*/

void TWI_write(char i2c,char data);

/*
    Function name         :  TWI_stop
    Function Returns      :  void
    Function Arguments    :  char i2c
    Function Description  :  send stop bit.
*/

void TWI_stop(char i2c);

/*
    Function name         :  TWI_readWithACK
    Function Returns      :  char
    Function Arguments    :  char i2c,char ACK_NACK
    Function Description  :  read data from i2c.
*/

char TWI_readWithACK(char i2c, char ACK_NACK);

/*
    Function name         :  TWI_check
    Function Returns      :  char
    Function Arguments    :  char i2c.
    Function Description  :  Check about the connection of i2c.
*/

char TWI_check(char i2c);
