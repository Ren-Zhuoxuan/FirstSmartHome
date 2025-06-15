#include <cal_oled_device.h>
#include <config.h>

#if defined (CONFIG_SUPPORT_HAL)
    #include <driver_i2c.h>
    #include <driver_oled.h>
#endif

int CAL_OLEDDeviceInit(struct DisplayDevice *ptDev)
{
#if defined (CONFIG_SUPPORT_HAL)
    I2C_GPIO_ReInit();
    OLED_Init();
    return 0;
#elif defined (CONFIG_SUPPORT_NOHAL)
    return NOHAL_OLEDDeviceInit(ptDev);
#endif
}

void CAL_OLEDDeviceFlush(struct DisplayDevice *ptDev)
{
#if defined (CONFIG_SUPPORT_HAL)
    OLED_Copy(ptDev->FBBase);
#elif defined (CONFIG_SUPPORT_NOHAL)
    NOHAL_OLEDDeviceFlush(ptDev);
#endif
}
