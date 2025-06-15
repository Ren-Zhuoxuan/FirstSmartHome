#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

typedef struct DisplayDevice {
	char *name; 
	void *FBBase; /*直接读写的显存*/
	int iXres; /*横向分辨率*/
	int iYres; /*纵向分辨率*/
	int iBpp; //每个像素要用多少位表示
	int iSize;
	int (*Init)(struct DisplayDevice *ptDev); /*硬件初始化*/
	void (*Flush)(struct DisplayDevice *ptDev); /*把FBBase数据刷到显存中*/
	/*把ix iy的像素设置为颜色dwColor*/
	int (*SetPixel)(struct DisplayDevice *ptDev,int iX,int iY,unsigned int dwColor);//0x00RRGGBB
	struct DisplayDevice *pNext;
}DisplayDevice, *PDisplayDevice;


void DisplayDeviceRegister(PDisplayDevice ptDispayDevice);
PDisplayDevice __GetDisplayDevice(char *name);


#endif /*__DISPLAY_DEVICE_H*/
