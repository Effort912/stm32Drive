#include "BH1750.h"

//iic接口初始化
/**
		PB6->SCL
		PB7->SDA
*/

void Light_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能A端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIOB6,7
 	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);	

	Single_Write_BH1750(0x01);
}

void Single_Write_BH1750(uchar REG_Address)
{
   IIC_Start();                  //起始信号
   IIC_Send_Byte(BHAddWrite);   //发送设备地址+写信号
   IIC_Send_Byte(REG_Address);    //内部寄存器地址，
  //  BH1750_SendByte(REG_data);       //内部寄存器数据，
   IIC_Stop();                   //发送停止信号
}

void bh_data_send(u8 command)
{
    do{
    IIC_Start();                      //iic起始信号
    IIC_Send_Byte(BHAddWrite);       //发送器件地址
    }while(IIC_Wait_Ack());           //等待从机应答
    IIC_Send_Byte(command);          //发送指令
    IIC_Wait_Ack();                   //等待从机应答
    IIC_Stop();                       //iic停止信号
}

u16 bh_data_read(void)
{
	u16 buf;
	IIC_Start();                       //iic起始信号
	IIC_Send_Byte(BHAddRead);         //发送器件地址+读标志位
	IIC_Wait_Ack();                     //等待从机应答
	buf=IIC_Read_Byte(1);              //读取数据
	buf=buf<<8;                        //读取并保存高八位数据
	buf+=0x00ff&IIC_Read_Byte(0);      //读取并保存第八位数据
	IIC_Stop();                        //发送停止信号 
	return buf; 
}