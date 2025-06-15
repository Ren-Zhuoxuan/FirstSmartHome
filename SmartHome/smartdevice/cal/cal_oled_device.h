#ifndef __CAL_OLED_DEVICE_H
#define __CAL_OLED_DEVICE_H
#include "display_device.h"

int CAL_OLEDDeviceInit(struct DisplayDevice *ptDev);
void CAL_OLEDDeviceFlush(struct DisplayDevice *ptDev);

#endif /*__CAL_OLED_DEVICE_H*/
