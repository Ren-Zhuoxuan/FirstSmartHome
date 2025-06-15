#include <oled_device.h>
#include <kal_oled_device.h>
/* 128*64bit 1024bytes*/
static unsigned char g_OLEDFramebuffer[1024];


static int OLEDDeviceInit(struct DisplayDevice *ptDev)
{
    //初始化OLED硬件
    return KAL_OLEDDeviceInit(ptDev);
}

static void OLEDDeviceFlush(struct DisplayDevice *ptDev)
{
    /*把Framebuffer的数据搬到OLED自带的显存中*/
    KAL_OLEDDeviceFlush(ptDev);
}

static int OLEDSetPixel(struct DisplayDevice *ptDev,int iX,int iY,unsigned int dwColor)
{
    unsigned char *buf = ptDev->FBBase;
    int page;
    unsigned char *byte;
    int bit;
    if (iX >= ptDev->iXres || iY >= ptDev->iYres)
    {
        return -1;
    }
    
    page = iY / 8;
    byte = buf + page*128 + iX;
    bit = iY % 8;

    if (dwColor)
    {
        *byte |= (1 << bit);
    }
    else
    {
        *byte &= ~(1 << bit);
    }
    
    return 0;

}


static DisplayDevice g_tOLEDDevice = {
    "OLED",
    g_OLEDFramebuffer,
    128,
    64,
    1,
    128*64*1/8,
    OLEDDeviceInit,
    OLEDDeviceFlush,
    OLEDSetPixel
};

void AddDisplayDeviceOLED(void)
{
    DisplayDeviceRegister(&g_tOLEDDevice);
}
