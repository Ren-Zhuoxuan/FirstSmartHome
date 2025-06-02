#ifndef __CAL_TIMER_H
#define __CAL_TIMER_H
#include "stm32f1xx_hal.h"
#include <input_system.h>
TIME_T CAL_GetTime(void);
void CAL_Delay(unsigned int DelayMS);

#endif /*__CAL_TIMER_H*/
