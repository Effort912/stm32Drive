void SPI1_Init(void){
	
	SPI_InitTypeDef SPI_InitStruc;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	GPIOInit(SPI1_MOSI_PORT,SPI1_MOSI_PIN,GPIO_Mode_AF_PP);
	GPIOInit(SPI1_SCK_PORT ,SPI1_SCK_PIN ,GPIO_Mode_AF_PP);
	
	SPI_Cmd(SPI1,DISABLE);
	SPI_InitStruc.SPI_Direction 				= SPI_Direction_1Line_Tx;				//只发送数据模式 可以改成同时接收和发送，发送数据函数要取消注释
	SPI_InitStruc.SPI_Mode 							= SPI_Mode_Master;
	SPI_InitStruc.SPI_DataSize  				= SPI_DataSize_8b;
	SPI_InitStruc.SPI_CPOL 							= SPI_CPOL_High;								//时钟线
	SPI_InitStruc.SPI_CPHA 							= SPI_CPHA_2Edge;								//偶边缘检测
	SPI_InitStruc.SPI_NSS 							= SPI_NSS_Soft;
	SPI_InitStruc.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStruc.SPI_CRCPolynomial 		= 7;
	SPI_InitStruc.SPI_FirstBit 					= SPI_FirstBit_MSB;
	SPI_Init(SPI1,&SPI_InitStruc);
	SPI_Cmd(SPI1,ENABLE);
	
}

u8 SPI_ReadByte(SPI_TypeDef *spi, u8 dat)
{
	while((spi->SR & 0x02) == 0);
	spi->DR = dat;
//	while((spi->SR & 0x01) == 0);
//	return (spi->DR);
	return 0;
}