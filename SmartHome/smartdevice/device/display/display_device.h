#ifndef __DISPLAY_DEVICE_H
#define __DISPLAY_DEVICE_H

typedef struct DispayDevice {
	char *name;
	void *FBBase;
	int iXres;
	int iYres;
	int iBpp; //每个像素要用多少位表示
	int (*Init)(struct DispayDevice *ptDev);
	void (*Flush)(struct DispayDevice *ptDev);
	int (*SetPixel)(struct DispayDevice *ptDev,int iX,int iY,unsigned int dwColor);//0x00RRGGBB
}DispayDevice, *PDispayDevice;


PDispayDevice GetDispayDevice(int which);


#endif /*__DISPLAY_DEVICE_H*/
