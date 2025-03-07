#include "wiring_constants.h"
#include "wiring_digital.h"
#include <Arduino.h>
#include <cstdint>
#include <vector>

#define LED1 PC13
#define LED2 PC14
#define LED3 PC15

class LED_flow {
  public:
    LED_flow(std::vector<uint32_t> pins) : _pins(pins) {}
    void flow() {
      
    }
  private:
    std::vector<uint32_t> _pins;
    std::vector<bool> _states;
};

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {

}
