#include <utils.hpp>
#include <led.hpp>
#include <serial.hpp>

void setup() {
  xTaskCreate(vTask_Led, 
    "Led Task", 
    128, 
    (void*)(new flow_led({LED})), 
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
