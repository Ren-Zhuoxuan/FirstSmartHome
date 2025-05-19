#include <input_system.h>
#include <input_buffer.h>
#include <stdio.h>
#include "input_test.h"

void input_test(void)
{
    InputEvent event;

    AddInputDevices();
    InitInputDevices();
    while (1)
    {
        if(GetInputEvent(&event) == 0)
        {
            printf("get input event:\r\n");
            printf("type:%d\r\n",event.eType);
            printf("time:%d\r\n",event.time);
            printf("key:%d\r\n",event.iKey);
            printf("pressure:%d\r\n",event.iPressure);
        }
    }
}
