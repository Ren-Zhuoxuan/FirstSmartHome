#include <display_system.h>
#include <oled_device.h>
void AddDisplayDevices(void)
{
    AddDisplayDeviceOLED();
}

PDisplayDevice GetDisplayDevice(char *name)
{
    return __GetDisplayDevice(name);
}

