#ifndef __DHT11_H
#define __DHT11_H 
#include "sys.h"   

 
//IO��������
#define DHT11_IO_IN()  {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=(u32)8<<8;}
#define DHT11_IO_OUT() {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=(u32)3<<8;}
////IO��������											   
#define	DHT11_DQ_OUT PBout(10) //���ݶ˿�	PB10 
#define	DHT11_DQ_IN  PBin(10)  //���ݶ˿�	PB10 


u8 DHT11_Init(void);//��ʼ��DHT11
u8 DHT11_Read_Data(u8 *temp_H,u8 *temp_L,u8 *humi_H,u8 *humi_L);//��ȡ��ʪ��
u8 DHT11_Read_Byte(void);//����һ���ֽ�
u8 DHT11_Read_Bit(void);//����һ��λ
u8 DHT11_Check(void);//����Ƿ����DHT11
void DHT11_Rst(void);//��λDHT11    
#endif















