#include "WSerial.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include <utils.hpp>
#include <led.hpp>
#include <btn.hpp>
#include <AHT20.hpp>

aht20* aht20_sensor;

void setup() {
  // xTaskCreate(vTask_Led, 
  //   "Led Task", 
  //   128, 
  //   (void*)(new flow_led({LED1_Local})), 
  //   1, 
  //   NULL
  // );

  // vTaskStartScheduler();

  Serial.begin(115200);
  pinMode(LED1_Local, OUTPUT);
  // aht20_sensor = new aht20();
  Adafruit_AHTX0 _aht;
  Wire.setSCL(PB13);
  Wire.setSDA(PB14);

  Wire.begin();
  _aht.begin(&Wire);
}

// btn btn({{BTN1, VCC}, {BTN2, VCC}});
// flow_led* led3 = new flow_led({LED3});

void loop() {
  digitalWrite(LED1_Local, digitalRead(LED1_Local) ^ 1);
  delay(1000);
}
