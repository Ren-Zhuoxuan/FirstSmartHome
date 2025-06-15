#include <display_device.h>
#include <string.h>
static PDisplayDevice g_ptDispayDevices;

//注册DispayDevice

void DisplayDeviceRegister(PDisplayDevice ptDispayDevice)
{
    ptDispayDevice->pNext = g_ptDispayDevices;
    g_ptDispayDevices = ptDispayDevice;
}

PDisplayDevice __GetDisplayDevice(char *name)
{
    PDisplayDevice pTmp = g_ptDispayDevices;
    while (pTmp)
    {
        if (strcmp(pTmp->name,name) == 0)
        {
            return pTmp;
        }
        else
        {
            pTmp = pTmp->pNext;
        }
    }
    return NULL;
}

