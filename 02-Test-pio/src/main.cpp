#include "serial.hpp"
#include <Arduino.h>
#include <cstddef>
#include <led.hpp>
#include <btn.hpp>

#include <FreeRTOS.h>
#include <task.h>

btn btn({{PA0, GND}});

void setup() {
  xTaskCreate(vTask_Led, 
    "Led Task", 
    128, 
    (void*)(new flow_led({LED_BUILTIN})), 
    1, 
    NULL
  );

  xTaskCreate(vTask_Serial, 
    "Serial Task", 
    256, 
    NULL, 
    1, 
    NULL
  );

  vTaskStartScheduler();
}

void loop() {
}
