/**
  ******************************************************************************
  * @file    main.c
  * @author  Martín R.
  * @version V1.0
  * @date    05-01-2020
  * @brief   HelloWorld ejemplo Blink LED para testear que la placa funcione. SanityCheck!
  ******************************************************************************
*/

#include "stm32f10x.h"
	int i = 0;
	int j = 0;

void initGPIO(void)
{
	// Habilito periferico de IO
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	// LED Salida
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	gpio.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC,&gpio);

}


int main(void)
{

initGPIO();
while(1)
{

	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	j = 0;
	i = 0;

	while (j < 10)
	{
		i = 0;
		while (i<32000)
		{
			i++;
		}
		j++;
	}

	j = 0;
	i = 0;

	GPIO_ResetBits(GPIOC, GPIO_Pin_13);

	while (j < 10)
	{
		i = 0;
		while (i<32000)
		{
			i++;
		}
		j++;
	}

}


}
