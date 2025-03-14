#include <led.hpp>

flow_led::flow_led(std::vector<uint32_t> leds) : _leds(leds) {
    for (auto led : _leds) {
        pinMode(led, OUTPUT);
    }

    _states.resize(_leds.size(), false);
    _states[1] = true;
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

void flow_led::blink(uint32_t index){
    if (index >= _leds.size()) {
        return;
    }

    digitalWrite(_leds[index], !digitalRead(_leds[index]));
}

void flow_led::flow(void) {
    if (millis() - _loc_millis < _interval) {
        return;
    }

    _loc_millis = millis();

    uint32_t index = 0;

    for (auto led : _leds) {
        digitalWrite(led, _states[index]);
        index++;
    }

    _states.insert(_states.end(), _states[0]);
    _states.erase(_states.begin());
}

void flow_led::speed_up(void) {
    if (_interval < 10) {
        return;
    }

    _interval = _interval / 2;
}

#include <btn.hpp>

void vTask_Led(void *pvParameters) {
    flow_led *flow = (flow_led *)pvParameters;
  
    while (1) {
        flow->toggle();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
