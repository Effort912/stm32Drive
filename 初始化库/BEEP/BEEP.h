#ifndef __BEEP_H
#define __BEEP_H

#include "sys.h"
#include "stm32f10x.h"


#define Beep PBout(5)	// PB4

void BEEP_Init(void);

#endif	
