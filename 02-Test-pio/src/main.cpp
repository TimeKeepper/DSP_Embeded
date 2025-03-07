#include <Arduino.h>
#include <cassert>
#include <vector>



class flow_led {
  public:
    flow_led(std::vector<uint32_t> leds) : _leds(leds) {
      assert(!_leds.size());
      for (auto led : _leds) {
        pinMode(led, OUTPUT);
      }
    }

    void toggle(void) {
      for (auto led : _leds) {
        digitalWrite(led, !digitalRead(led));
      }
    }

  private:
    std::vector<uint32_t> _leds;
};

flow_led flow({LED_BUILTIN});
void setup() {
}

void loop() {
  flow.toggle();
  delay(1000);
}
