#ifndef __LED_DEVICE_H
#define __LED_DEVICE_H

#define LED_WHITE 0
#define LED_BLUE  1
#define LED_GREEN 2

typedef struct LEDDevice
{
    int which;
    int (*Init)(struct LEDDevice *ptLEDDevice);
    int (*Control)(struct LEDDevice *ptLEDDevice,int iState);
    void (*SetColor)(struct LEDDevice *ptLEDDevice,int iColor);
    void (*SetBrightness)(struct LEDDevice *ptLEDDevice,int iBrightness);
}LEDDevice,*PLEDDevice;

PLEDDevice GetLEDDevice(int which);

#endif /*__LED_DEVICE_H*/
