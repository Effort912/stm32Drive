#ifndef __LED_H
#define  __LED_H
#include "STM32F10X.H"
#define BITAND(addr,bitnum)					((addr&0xF0000000)+0X2000000+((addr&0XFFFFF)<<5)+(bitnum<<2))
#define MEM_ADR(addr)								*((volatile unsigned long *)(addr))
#define BIT_ADDR(addr,bitnum)				MEM_ADR(BITAND(addr,bitnum))

#define GPIOA_ODR										(GPIOA_BASE+12)
#define GPIOB_ODR										(GPIOB_BASE+12)
#define GPIOC_ODR										(GPIOC_BASE+12)
#define GPIOA_IDR										(GPIOA_BASE+8)
#define GPIOB_IDR										(GPIOB_BASE+8)
#define GPIOC_IDR										(GPIOC_BASE+8)

#define PAout(o)										BIT_ADDR(GPIOA_ODR,o)
#define PBout(o)										BIT_ADDR(GPIOB_ODR,o)
#define PCout(o)										BIT_ADDR(GPIOC_ODR,o)

#define PAin(o)											BIT_ADDR(GPIOA_IDR,o)
#define PBin(o)											BIT_ADDR(GPIOB_IDR,o)
#define PCin(o)											BIT_ADDR(GPIOC_IDR,o)

#define LED_PORT										GPIOC
#define LED_CLK											RCC_APB2Periph_GPIOC
#define LED1_PIN										GPIO_Pin_13

#define LED1												PCout(13)

extern u8 led_sw;

void LED_Config(void);

void Led_Tick(void);
void GpioInit(GPIO_TypeDef *gpio,uint16_t pin,GPIOMode_TypeDef mode);

#endif

