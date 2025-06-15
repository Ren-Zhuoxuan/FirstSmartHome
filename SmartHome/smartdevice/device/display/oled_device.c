#include <oled_device.h>

/* 128*64bit 1024bytes*/
static unsigned char g_OLEDFramebuffer[1024];


static int OLEDDeviceInit(struct DispayDevice *ptDev)
{
    //初始化OLED硬件
    return KAL_OLEDDeviceInit(ptDev);
}

static void OLEDDeviceFlush(struct DispayDevice *ptDev)
{
    /*把Framebuffer的数据搬到OLED自带的显存中*/
    KAL_OLEDDeviceFlush(ptDev);
}

static int OLEDSetPixel(struct DispayDevice *ptDev,int iX,int iY,unsigned int dwColor)
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


static DispayDevice g_tOLEDDevice = {
    "OLED",
    g_OLEDFramebuffer,
    128,
    64,
    1,
    OLEDDeviceInit,
    OLEDDeviceFlush,
    OLEDSetPixel
};
