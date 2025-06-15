#include <cal_oled_device.h>
#include <config.h>

#if defined (CONFIG_SUPPORT_HAL)
    #include <driver_i2c.h>
    #include <driver_oled.h>
#endif

static int CAL_OLEDDeviceInit(struct DispayDevice *ptDev)
{
#if defined (CONFIG_SUPPORT_HAL)
    I2C_GPIO_ReInit();
    OLED_Init();
    return 0;
#elif
    return NOHAL_OLEDDeviceInit(ptDev);
#endif
}

static void CAL_OLEDDeviceFlush(struct DispayDevice *ptDev)
{
#if defined (CONFIG_SUPPORT_HAL)
    OLED_Copy(ptDev->FBBase);
#elif
    NOHAL_OLEDDeviceFlush(ptDev);
#endif
}