#include "input_system.h"

static PInputDevice g_ptInputDevices;

//注册InputDevice

void InputDeviceRegister(PInputDevice ptInputDevice)
{
    ptInputDevice->pNext = g_ptInputDevices;
    g_ptInputDevices = ptInputDevice;
}

void AddInputDevices(void)
{
    AddInputDeviceGPIOKey();
}

void InitInputDevices(void)
{
    PInputDevice pDev = g_ptInputDevices;
    while(pDev)
    {
        pDev->DeviceInit();
        pDev = pDev->pNext;
    }
}
