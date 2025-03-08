#ifndef __ADC_HPP__
#define __ADC_HPP__

#include <utils.hpp>

class Adc {
public:
    Adc();
    uint32_t read(void);
    float read_voltage(void);
private:
    ADC_HandleTypeDef hadc1;
    ADC_ChannelConfTypeDef sConfig;
};

#endif
