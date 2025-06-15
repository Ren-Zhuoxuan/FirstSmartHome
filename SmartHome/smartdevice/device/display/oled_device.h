#ifndef __OLED_DEVICE_H
#define __OLED_DEVICE_H

#include "display_device.h"

static int OLEDDeviceInit(struct DisplayDevice *ptDev);
static void OLEDDeviceFlush(struct DisplayDevice *ptDev);
static int OLEDSetPixel(struct DisplayDevice *ptDev,int iX,int iY,unsigned int dwColor);
void AddDisplayDeviceOLED(void);


#endif /*__OLED_DEVICE_H*/
