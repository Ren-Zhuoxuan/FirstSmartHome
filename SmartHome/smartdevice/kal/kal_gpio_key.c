#include "kal_gpio_key.h"
#include <cal_gpio_key.h>

void KAL_GPIOKeyInit(void)
{
    //对于裸机注册中断
    CAL_GPIOKeyInit();
    //对于RTOS创建任务

}
