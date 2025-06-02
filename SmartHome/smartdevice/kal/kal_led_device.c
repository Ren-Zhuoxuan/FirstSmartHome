#include <led_device.h>
#include <cal_led_device.h>
#include "kal_led_device.h"

int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    /* 对于裸机/FreeRTOS */
	return CAL_LEDDeviceInit(ptLEDDevice);

	/* 对于RT-Thread */

	/* 对于Linux */
}

int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState)
{
    /* 对于裸机/FreeRTOS */
	return CAL_LEDDeviceControl(ptLEDDevice,iState);

	/* 对于RT-Thread */

	/* 对于Linux */
}
