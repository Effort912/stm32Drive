#include "LED.H"

u8 led_sw = 1;

void LED_Config()
{
	  GpioInit(LED_PORT,LED1_PIN,GPIO_Mode_Out_PP);
}

void GpioInit(GPIO_TypeDef *gpio,uint16_t pin,GPIOMode_TypeDef mode)
{
		static uint8_t initFlag = 0;
		GPIO_InitTypeDef initGpio;
		if(initFlag == 0)
		{
				RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE);
				initFlag = 1;
		}
		initGpio.GPIO_Mode = mode;
		initGpio.GPIO_Speed = GPIO_Speed_50MHz;
		initGpio.GPIO_Pin = pin;
		GPIO_Init(gpio,&initGpio);
}

void Led_Tick(void)
{
		static u16 cou = 0;
	
		if(led_sw == 1)
		{
				cou++;
				if(cou > 100)
				{
						cou = 0;
						LED1 = !LED1;
				}
		} 
		
		if(led_sw == 2)
		{
			LED1 = 0;
		} 
		
		if(led_sw == 3)
		{
			LED1 = 1;
		}
}

