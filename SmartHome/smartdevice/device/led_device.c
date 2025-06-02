#include "led_device.h"
#include <kal_led_device.h>

static int LEDDeviceInit(struct LEDDevice *ptLEDDevice)
{
    return KAL_LEDDeviceInit(ptLEDDevice);
}


static int LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState)
{
    return KAL_LEDDeviceControl(ptLEDDevice,iState);
}

static LEDDevice g_tLEDDevices[] = {
    {LED_WHITE,LEDDeviceInit,LEDDeviceControl},
    {LED_BLUE, LEDDeviceInit,LEDDeviceControl},
    {LED_GREEN,LEDDeviceInit,LEDDeviceControl},
};

//使用LED子系统，首先要获得LED，再初始化
PLEDDevice GetLEDDevice(int which)
{
    if (which>=LED_WHITE && which<=LED_GREEN)
    {
        return &g_tLEDDevices[which];
    }
    else
    {
        return NULL;
    }
    
}

