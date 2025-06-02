#ifndef __KAL_LED_DEVICE_H
#define __KAL_LED_DEVICE_H
#include <led_device.h>

int KAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice);
int KAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState);


#endif /*__KAL_LED_DEVICE_H*/
