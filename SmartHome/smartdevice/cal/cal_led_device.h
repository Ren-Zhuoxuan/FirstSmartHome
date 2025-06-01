#ifndef __CAL_LED_DEVICE_H
#define __CAL_LED_DEVICE_H

int CAL_LEDDeviceInit(struct LEDDevice *ptLEDDevice);
int CAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState);

#endif /*__CAL_LED_DEVICE_H*/
