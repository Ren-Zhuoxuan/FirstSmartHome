#include "stm32f1xx_hal.h"
#include <cal_timer.h>

TIME_T CAL_GetTime(void)
{
    //tick中断里面 count++
    return HAL_GetTick();
}
