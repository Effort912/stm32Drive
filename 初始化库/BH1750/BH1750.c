#include "BH1750.h"

//iic�ӿڳ�ʼ��
/**
		PB6->SCL
		PB7->SDA
*/

void Light_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��A�˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	 
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�ٶ�50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	  //��ʼ��GPIOB6,7
 	GPIO_SetBits(GPIOB,GPIO_Pin_6|GPIO_Pin_7);	

	Single_Write_BH1750(0x01);
}

void Single_Write_BH1750(uchar REG_Address)
{
   IIC_Start();                  //��ʼ�ź�
   IIC_Send_Byte(BHAddWrite);   //�����豸��ַ+д�ź�
   IIC_Send_Byte(REG_Address);    //�ڲ��Ĵ�����ַ��
  //  BH1750_SendByte(REG_data);       //�ڲ��Ĵ������ݣ�
   IIC_Stop();                   //����ֹͣ�ź�
}

void bh_data_send(u8 command)
{
    do{
    IIC_Start();                      //iic��ʼ�ź�
    IIC_Send_Byte(BHAddWrite);       //����������ַ
    }while(IIC_Wait_Ack());           //�ȴ��ӻ�Ӧ��
    IIC_Send_Byte(command);          //����ָ��
    IIC_Wait_Ack();                   //�ȴ��ӻ�Ӧ��
    IIC_Stop();                       //iicֹͣ�ź�
}

u16 bh_data_read(void)
{
	u16 buf;
	IIC_Start();                       //iic��ʼ�ź�
	IIC_Send_Byte(BHAddRead);         //����������ַ+����־λ
	IIC_Wait_Ack();                     //�ȴ��ӻ�Ӧ��
	buf=IIC_Read_Byte(1);              //��ȡ����
	buf=buf<<8;                        //��ȡ������߰�λ����
	buf+=0x00ff&IIC_Read_Byte(0);      //��ȡ������ڰ�λ����
	IIC_Stop();                        //����ֹͣ�ź� 
	return buf; 
}