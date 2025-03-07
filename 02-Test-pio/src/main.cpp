
#include "variant_BLACKPILL_F411CE.h"
#include <Arduino.h>
#include <cstddef>
#include <led.hpp>
#include <USBSerial.h>

#include <FreeRTOS.h>
#include <task.h>

void setup() {
  xTaskCreate(vTask_Led, 
    "Led Task", 
    128, 
    (void*)(new flow_led({LED_BUILTIN})), 
    1, 
    NULL
  );

  vTaskStartScheduler();
}

void loop() {
  // SerialUSB.begin();
  // SerialUSB.println("Hello, world!");

}
