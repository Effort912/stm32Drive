#ifndef __DHT11_H
#define __DHT11_H 
#include "sys.h"   

 
//IO方向设置
#define DHT11_IO_IN()  {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=(u32)8<<8;}
#define DHT11_IO_OUT() {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=(u32)3<<8;}
////IO操作函数											   
#define	DHT11_DQ_OUT PBout(10) //数据端口	PB10 
#define	DHT11_DQ_IN  PBin(10)  //数据端口	PB10 


u8 DHT11_Init(void);//初始化DHT11
u8 DHT11_Read_Data(u8 *temp_H,u8 *temp_L,u8 *humi_H,u8 *humi_L);//读取温湿度
u8 DHT11_Read_Byte(void);//读出一个字节
u8 DHT11_Read_Bit(void);//读出一个位
u8 DHT11_Check(void);//检测是否存在DHT11
void DHT11_Rst(void);//复位DHT11    
#endif















