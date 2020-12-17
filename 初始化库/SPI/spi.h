#ifndef __LCD_DRIVER_H
#define __LCD_DRIVER_H

#include "stm32f10x.h"

#define SPI1_SCK_PORT			GPIOA
#define SPI1_SCK_PIN			GPIO_Pin_5
#define SPI1_MISO_PORT		GPIOA
#define SPI1_MISO_PIN 		GPIO_Pin_6
#define SPI1_MOSI_PORT 		GPIOA
#define SPI1_MOSI_PIN			GPIO_Pin_7

u8 SPI_ReadByte(SPI_TypeDef *spi, u8 dat);
void SPI1_Init(void);
