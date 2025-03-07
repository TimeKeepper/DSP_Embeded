#include "main.h"
#include "stm32g0xx_hal_gpio.h"

void user_code(void){
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    HAL_Delay(1000);
}
