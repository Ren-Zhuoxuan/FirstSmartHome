#include <stdio.h>
#include <led_device.h>
#include "led_test.h"
#include <stm32f1xx_hal.h>
#include <kal_timer.h>

void led_test(void)
{
    PLEDDevice p1 = GetLEDDevice(LED_WHITE);
    PLEDDevice p2 = GetLEDDevice(LED_BLUE);
    PLEDDevice p3 = GetLEDDevice(LED_GREEN);

    p1->Init(p1);
    p2->Init(p2);
    p3->Init(p3);

    while (1)
    {
        p1->Control(p1,1);
        p2->Control(p2,1);
        p3->Control(p3,1);
        KAL_Delay(500);
        p1->Control(p1,0);
        p2->Control(p2,0);  
        p3->Control(p3,0);
        KAL_Delay(500);
    }
    

}
