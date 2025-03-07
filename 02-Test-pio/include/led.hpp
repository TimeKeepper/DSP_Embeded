#ifndef __LED__HPP__
#define __LED__HPP__

#include <utils.hpp>

class flow_led {
public:
    flow_led(std::vector<uint32_t> leds);
    void toggle(void);
    void speed_up(void);
    
private:
    std::vector<uint32_t> _leds;

    uint32_t _loc_millis;
    uint32_t _interval;
};

void vTask_Led(void *pvParameters);

#endif