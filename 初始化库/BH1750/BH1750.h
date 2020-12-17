#ifndef __BH1750_H
#define __BH1750_H

#include "IIC.h"

void Light_Init(void);
void bh_data_send(u8 command);
u16 bh_data_read(void);
void Single_Write_BH1750(uchar REG_Address);

#endif