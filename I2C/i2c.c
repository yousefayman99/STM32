 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.c
 *
 * Author: Yousef ayman
 *
 *******************************************************************************/
 


#include "i2c.h"


/*
I2C2
PB10 -> SCL
PB11 -> SDA

I2C1
PB6 -> SCL
PB7 -> SDA

*/


// i2c_init()
void TWI_init(char i2c,unsigned short speed_mode)
{
	RCC->APB2ENR |= 1; 
	
	if(i2c==1)
	{
		RCC->APB1ENR |= 0x200000;
		// Pin enable 
		DIO_set_pin_dir(PB,6,OUT50,O_AF_OD);
		DIO_set_pin_dir(PB,7,OUT50,O_AF_OD);
		I2C1->CR1 |= 0x8000;
		I2C1->CR1 &= ~0x8000;
		I2C1->CR2 =0x8;
		I2C1->CCR = speed_mode;
		I2C1->TRISE = 0x9;
		I2C1->CR1 |= 1;
	}
	else if(i2c==2)
	{
		RCC->APB1ENR |= 0x400000;
		// Pin enable 
		DIO_set_pin_dir(PB,10,OUT50,O_AF_OD);
		DIO_set_pin_dir(PB,11,OUT50,O_AF_OD);
		I2C2->CR1 |= 0x8000;
		I2C2->CR1 &= ~0x8000;
		I2C2->CR2 =0x8;
		I2C2->CCR = speed_mode;
		I2C2->TRISE = 0x9;
		I2C2->CR1 |= 1;
	}

}

// Start step
void TWI_start(char i2c)
{
	if(i2c==1)
	{
		I2C1->CR1 |= 0x100;
		while (!(I2C1->SR1 & 1)){};
	}
	else if(i2c==2)
	{
		I2C2->CR1 |= 0x100;
		while (!(I2C2->SR1 & 1)){};
	}
}
// Sending the address + R or Write	
char TWI_write_address(char i2c, char address,char RW)
{
	char check = 1;
	volatile int tmp;
	if(i2c==1)
	{
		I2C1->DR = ((address & 0xFE)|RW);
		while((I2C1->SR1 & 2)==0){
		if(I2C1->SR1 & 0x0F00)
		{
			check = 0;
			I2C1->SR1  &= ~0x0F00;
			break;
		}
		
		};
		if(check)
		{
		while((I2C1->SR1 & 2)){
			tmp = I2C1->SR1;
			tmp = I2C1->SR2;
			if((I2C1->SR1 & 2)==0)
			{
				break;
			}
		}
	}
	}
	else if(i2c==2)
	{
		I2C2->DR = ((address & 0xFE)|RW);
		while((I2C2->SR1 & 2)==0){
		if(I2C2->SR1 & 0x0F00)
		{
			check = 0;
			I2C2->SR1  &= ~0x0F00;
			break;
		}
		
		
		};
		if(check)
		{
		while((I2C2->SR1 & 2)){
			tmp = I2C2->SR1;
			tmp = I2C2->SR2;
			if((I2C2->SR1 & 2)==0)
			{
				break;
			}
		}
		}
	}
	return check;
}
// Sending data step
void TWI_write(char i2c,char data)
{
	if(i2c==1)
	{
		while((I2C1->SR1 & 0x80) == 0){}
			I2C1->DR = data;
		while((I2C1->SR1 & 0x80) == 0){}
	}
	else if(i2c==2)
	{
		while((I2C2->SR1 & 0x80) == 0){}
			I2C2->DR = data;
		while((I2C2->SR1 & 0x80) == 0){}
	}
}
// Stop step
void TWI_stop(char i2c)
{
	volatile int tmp;
	if(i2c==1)
	{
		tmp = I2C1->SR1;
		tmp = I2C1->SR2;
		I2C1->CR1 |= 0x200;
	}
	else if(i2c==2)
	{
		tmp = I2C2->SR1;
		tmp = I2C2->SR2;
		I2C2->CR1 |= 0x200;
	}
}
// i2c_write()
void TWI_write_multiple_data(char i2c, char address,char data[])
{
	int i = 0;
	
	TWI_start(i2c);
	
	TWI_write_address(i2c, address,0);
	
	while(data[i])
		{
			TWI_write(i2c,data[i]);
			i++;
		}
	TWI_stop(i2c);
}

// Receiving data
char TWI_readWithACK(char i2c, char ACK_NACK)
{
	char temp;
	if(i2c==1)
	{
		I2C1->CR1 |= 0x0400;
		while((I2C1->SR1 & 0x40)==0){}
			temp = I2C1->DR;
		if(ACK_NACK)
		{
			I2C1->CR1 &= ~0x0400;
		}
		
	}
	else if(i2c==2)
	{
		I2C2->CR1 |= 0x0400;
		while((I2C2->SR1 & 0x40)==0){}
			temp = I2C2->DR;
		if(ACK_NACK)
		{
			I2C2->CR1 &= ~0x0400;
		}
		
	}
	return temp;
}

char TWI_check(char i2c)
{
	char check=1;
	if(i2c ==1)
	{
		if(I2C1->SR2 & 2)
		{
			check =0;
		}
	}
	else if(i2c ==2)
	{
		if(I2C2->SR2 & 2)
		{
			check =0;
		}
	}
	return check;
}
