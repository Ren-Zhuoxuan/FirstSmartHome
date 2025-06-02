#ifndef __DRIVER_LED_H
#define __DRIVER_LED_H
#include <led_device.h>
#include "stm32f1xx_hal.h"

int HAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState);


#endif /* __DRIVER_LED_H */
