#ifndef __NET_DEVICE_H
#define __NET_DEVICE_H

#ifndef NULL
#define NULL (void *)0
#endif


typedef struct NetDevice
{
    char *name;
    char ip[4]; //IP地址
    char mac[6];
    int (*Init)(struct NetDevice *ptDev);
    int (*Connect)(struct NetDevice *ptDev,char *SSID,char *password); //连接网络函数
    int (*DisConnect)(struct NetDevice *ptDev); 
    //收发数据 三要素 source dest data 
    int (*Send)(struct NetDevice *ptDev,char *Type,char *pDestIP,int iDestPort,unsigned char *Data,int iLen);
    //iLocalPort 本地端口 piLen保存接受的数据长度 Data接收的数据 还有超时时间 Type:udp/tcp
    int (*Recv)(struct NetDevice *ptDev,char *Type,int iLocalPort,char *pSrcIP,unsigned char *Data,int *piLen,int iTimeoutMS);
}NetDevice,*PNetDevice;


#endif /* __NET_DEVICE_H */
