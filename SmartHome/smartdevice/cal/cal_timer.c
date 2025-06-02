#include <cal_timer.h>

TIME_T CAL_GetTime(void)
{
    //tick中断里面 count++
    return HAL_GetTick();
}

void CAL_Delay(unsigned int DelayMS)
{
    HAL_Delay(DelayMS);
}
