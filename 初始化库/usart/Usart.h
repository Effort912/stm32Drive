#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>

#define U1										USART1
#define U1_CLK								RCC_APB2Periph_USART1
#define U1_CLK_Cmd						RCC_APB2PeriphClockCmd
#define U1_BAUDRATE						115200

#define U1_TX_PORT						GPIOA
#define U1_TX_PIN							GPIO_Pin_9
#define U1_RX_PORT						GPIOA  
#define U1_RX_PIN							GPIO_Pin_10            
#define U1_GPIO_CLK						RCC_APB2Periph_GPIOA
#define U1_GPIO_CLK_Cmd				RCC_APB2PeriphClockCmd

#define U1_IRQ								USART1_IRQn
#define U1_IRQHandler					USART1_IRQHandler

#define USART_FLAG_MSG						0X01



#define U1_BUF_LEN	30

//向外部声明变量，使其他文件可以使用这个变量
extern u8 U1_Flag; 
extern u8 U1_Buf[U1_BUF_LEN];
extern u8 U1_Len;

void U1_Config(void);
void U1_Tick(void);


void USART_SendByte( USART_TypeDef *pUSARTx, uint8_t ch);
void USART_SendString( USART_TypeDef *pUSARTx, uint8_t *str, uint16_t len);

#endif

