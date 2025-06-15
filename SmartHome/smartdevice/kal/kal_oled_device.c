#include <kal_oled_device.h>
#include <config.h>

static int KAL_OLEDDeviceInit(struct DispayDevice *ptDev)
{
#if defined (CONFIG_NOOS)
    return CAL_OLEDDeviceInit(ptDev);
#elif defined (CONFIG_FREERTOS)
    return FreeRTOS_OLEDDeviceInit(ptDev);
#elif defined (CONFIG_RTTHREAD)
    return RTThread_OLEDDeviceInit(ptDev);
#endif
}

static void KAL_OLEDDeviceFlush(struct DispayDevice *ptDev)
{
#if defined (CONFIG_NOOS)
    CAL_OLEDDeviceFlush(ptDev);
#elif defined (CONFIG_FREERTOS)
    return FreeRTOS_OLEDDeviceFlush(ptDev);
#elif defined (CONFIG_RTTHREAD)
    return RTThread_OLEDDeviceFlush(ptDev);
#endif
}

