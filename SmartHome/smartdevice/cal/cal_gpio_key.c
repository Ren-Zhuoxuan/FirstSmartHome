#include "cal_gpio_key.h"


void CAL_GPIOKeyInit(void)
{
    //调用芯片相关代码 注册GPIO中断

    //对于ST芯片
    KEY_GPIO_ReInit();
}
