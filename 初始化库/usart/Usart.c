#include "Usart.h"
#include "led.h"
#include "string.h"

void U1_NVIC_Configuration(void)
{
		NVIC_InitTypeDef					NVIC_InitStructure;
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
		NVIC_InitStructure.NVIC_IRQChannel = U1_IRQ;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
}
void U1_Config(void)
{
		GPIO_InitTypeDef       GPIO_InitStructure;
		USART_InitTypeDef			 USART_InitStructure;
		
		U1_CLK_Cmd(U1_CLK, ENABLE);
		U1_GPIO_CLK_Cmd(U1_GPIO_CLK, ENABLE);
			 
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Pin = U1_TX_PIN;
		GPIO_Init(U1_TX_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStructure.GPIO_Pin = U1_RX_PIN;
		GPIO_Init(U1_RX_PORT, &GPIO_InitStructure);
		
		USART_InitStructure.USART_BaudRate = 115200;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		USART_InitStructure.USART_StopBits = USART_StopBits_1;
		USART_InitStructure.USART_Parity = USART_Parity_No;
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_Init(U1, &USART_InitStructure);
		
		U1_NVIC_Configuration();
		
		USART_ITConfig(U1, USART_IT_RXNE, ENABLE);
		USART_Cmd(U1, ENABLE);
}

void USART_SendByte( USART_TypeDef *pUSARTx, uint8_t ch)
{
		USART_SendData( pUSARTx, ch);
	  while( USART_GetFlagStatus( pUSARTx, USART_FLAG_TXE) == RESET);
}


void USART_SendString( USART_TypeDef *pUSARTx, uint8_t *str, uint16_t len)
{
		unsigned int count = 0;
			
	  while(count < len )
		{
				USART_SendByte( pUSARTx, *(str+count));
			  count++;
		}
		while( USART_GetFlagStatus( pUSARTx, USART_FLAG_TC) == RESET);
}

#define U1_BUF_LEN	30
u8 U1_Buf[U1_BUF_LEN];
u8 U1_Cou = 0;
u8 U1_Len = 0;
u8 U1_Time = 0; 
u8 U1_Flag = 0;

void U1_IRQHandler(void)
{
		if( USART_GetITStatus( U1, USART_IT_RXNE) != RESET)
		{
				if(U1_Cou < U1_BUF_LEN)
				{
						U1_Buf[U1_Cou] = USART_ReceiveData(U1); //接收一位电脑发送过来的数据
						U1_Cou++;	
						U1_Time = 0;
					
				}
		}
}
void U1_Tick(void)
{
		if(U1_Cou)
		{
				U1_Time++;
				if(U1_Time > 4)
				{
						U1_Time = 0;
						U1_Len = U1_Cou;
						U1_Cou = 0;
						U1_Flag |= USART_FLAG_MSG;
						U1_Buf[U1_Len] = 0;
				}
		}
}



//重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *F)
{
		USART_SendData(U1, (uint8_t) ch);
		while(USART_GetFlagStatus(U1, USART_FLAG_TXE) == RESET);
	  return(ch);
}
///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		while(USART_GetFlagStatus(U1, USART_FLAG_RXNE) == RESET);
	  return (int) USART_ReceiveData(U1);
}



