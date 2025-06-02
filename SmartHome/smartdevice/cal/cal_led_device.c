#include <led_device.h>
#include <driver_led.h>
#include "cal_led_device.h"

int CAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    /* 对于hal */
	/* 已经在MX_GPIO_Init初始化了引脚 */
	return 0;

}

int CAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState)
{
    /* 对于hal */
	return HAL_LEDDeviceControl(ptLEDDevice,iState);
}


