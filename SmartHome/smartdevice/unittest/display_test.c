#include <stdio.h>
#include <display_system.h>
#include <display_device.h>
#include "display_test.h"
#include <string.h>

void display_test(void)
{
    PDisplayDevice ptDevice;
    char *name = "OLED";
    int x,y;

    AddDisplayDevices();
    
    ptDevice = GetDisplayDevice(name);
    if (!ptDevice)
    {
        printf("Can not DisplayDevices %s\r\n",name);
        return;
    }
    //初始化设备
    ptDevice->Init(ptDevice);

    //清除屏幕
    memset(ptDevice->FBBase,0,ptDevice->iSize);

    //中间画一条线
    y = ptDevice->iYres / 2; 
    for ( x = 0; x < ptDevice->iXres; x++)
    {
        ptDevice->SetPixel(ptDevice,x,y,1);
    }
    
    x = ptDevice->iXres / 2; 
    for ( y = 0; y < ptDevice->iYres; y++)
    {
        ptDevice->SetPixel(ptDevice,x,y,1);
    }

    //flush
    ptDevice->Flush(ptDevice);
}
