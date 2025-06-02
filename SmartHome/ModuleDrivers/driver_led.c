#include "driver_led.h"
#include "main.h"


int HAL_LEDDeviceControl(struct LEDDevice *ptLEDDevice,int iState)
{
    GPIO_PinState pinstate;
    if (!ptLEDDevice)
    {
        return -1;
    }
    
    pinstate = iState? GPIO_PIN_RESET : GPIO_PIN_SET;

    switch (ptLEDDevice->which)
    {
    case LED_WHITE:
        HAL_GPIO_WritePin(WHITE_GPIO_Port, WHITE_Pin, pinstate);
        break;
    case LED_BLUE:
        HAL_GPIO_WritePin(BLUE_GPIO_Port, BLUE_Pin, pinstate);
        break;
    case LED_GREEN:
        HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, pinstate);
        break;    
    default:
        return -1;
    }
    return 0;
}

