#ifndef __LED__HPP__
#define __LED__HPP__

#include <utils.hpp>

class flow_led {
public:
    flow_led(std::vector<uint32_t> leds);
    void toggle(void);
    void blink(uint32_t index);
    void flow(void);
    void speed_up(void);
    
private:
    std::vector<uint32_t> _leds;
    std::vector<bool> _states;

    uint32_t _loc_millis;
    uint32_t _interval;
};

void vTask_Led(void *pvParameters);

#define LED1 PC13
#define LED2 PC14
#define LED3 PC15

#endif