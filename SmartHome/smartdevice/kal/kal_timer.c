#include <kal_timer.h>

TIME_T KAL_GetTime(void)
{
    return CAL_GetTime();
}

void KAL_Delay(unsigned int DelayMS)
{
    CAL_Delay(DelayMS);
}
