#ifndef __INPUT_SYSTEM_H
#define __INPUT_SYSTEM_H

#define TIME_T int
#define INTPU_BUF_LEN 1024

typedef enum{
    INPUT_EVENT_TYPE_KEY,
    INPUT_EVENT_TYPE_TOUCH,
    INPUT_EVENT_TYPE_NET,
    INPUT_EVENT_TYPE_STDIO
}INPUT_EVENT_TYPE;

typedef struct InputEvent
{
    //定义时间 什么时候产生输入事件 在中断里面让定时器++，time=定时器记录时间
    //为了兼容裸机和Linux，需要定义宏，放在OS抽象层里面
    TIME_T time;
    INPUT_EVENT_TYPE eType;//哪种数据类型
    int iX; //触摸屏
    int iY;
    int iKey; //按键
    int iPressure; //按键状态
    char str[INTPU_BUF_LEN]; //网络数据和scanf
}InputEvent,*PInputEvent;


typedef struct InputDevice
{
    char *name;
    int (*GetInputEvent)(PInputEvent ptInputEvent);
    int (*DeviceInit)(void);
    int (*DeviceExit)(void);
    struct InputDevice *next;
}InputDevice,*PInputDevice;



#endif  /*__INPUT_SYSTEM_H*/ //避免重复包含头文件
