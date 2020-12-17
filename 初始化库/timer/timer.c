#include "timer.h"
#include "sys.h"

/*************定时器3********************************/
void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr;										//设置自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;									//设置时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//TIM向上计数
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;							//TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;		//先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;					//从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;							//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM3,ENABLE);
}

/******************定时器2********************************/
void TIM2_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	//定时器TIM2初始化
	TIM_TimeBaseStructure.TIM_Period = arr;										//设置自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler = psc;									//设置时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//设置时钟分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//TIM向上计数
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE );
	
	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;							//TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;		//先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;					//从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;							//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
}