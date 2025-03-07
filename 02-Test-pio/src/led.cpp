#include <led.hpp>

flow_led::flow_led(std::vector<uint32_t> leds) : _leds(leds) {
    for (auto led : _leds) {
        pinMode(led, OUTPUT);
    }

    _loc_millis = millis();
    _interval = 1000;
}

void flow_led::toggle(void) {
    if (millis() - _loc_millis < _interval) {
        return;
    }

    _loc_millis = millis();

    for (auto led : _leds) {
        digitalWrite(led, !digitalRead(led));
    }
}

void flow_led::speed_up(void) {
    if (_interval < 10) {
        return;
    }

    _interval = _interval / 2;
}

void vTask_Led(void *pvParameters) {
    flow_led *flow = (flow_led *)pvParameters;
  
    while (1) {
      flow->toggle();
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
