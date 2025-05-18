#include "input_system.h"
#include "input_buffer.h"
#include "gpio_key.h"
#include <kal_gpio_key.h>

static int GPIOKeyInit(void)
{
    KAL_GPIOKeyInit(); //在KAL层实现，支持裸机和RTOS
    return 0;
}


//为GPIO按键构造一个InputDevice
static InputDevice g_tKeyDevice = {
    "gpio_key",
    NULL,
    GPIOKeyInit,
    NULL,
};

void AddInputDeviceGPIOKey(void)
{
    InputDeviceRegister(&g_tKeyDevice);
}

