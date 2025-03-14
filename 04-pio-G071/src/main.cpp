#include "WSerial.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include <utils.hpp>
#include <led.hpp>
#include <btn.hpp>
#include <AHT20.hpp>

aht20 aht20;

void setup() {
  // xTaskCreate(vTask_Led, 
  //   "Led Task", 
  //   128, 
  //   (void*)(new flow_led({LED1, LED2})), 
  //   1, 
  //   NULL
  // );

  // vTaskStartScheduler();

  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
}

// btn btn({{BTN1, VCC}, {BTN2, VCC}});
// flow_led* led3 = new flow_led({LED3});

void LED_task(void) {
  static uint32_t loc_millis = millis();
  if(millis() - loc_millis < 1000) {
    return;
  }
  loc_millis = millis();

  digitalWrite(LED1, !digitalRead(LED1));
}

void loop() {
  // if (btn_states[0]->load()) {
  //   led3->toggle();
  //   btn_states[0]->store(false);
  // }

  LED_task();

  // aht20.read();
  // Serial.print("Temperature: ");
  // Serial.print(aht20.get_temperature());
  // Serial.print(" Humidity: ");
  // Serial.println(aht20.get_humidity());
}
