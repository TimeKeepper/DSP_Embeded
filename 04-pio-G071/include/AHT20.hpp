#ifndef __AHT20_HPP__
#define __AHT20_HPP__

#include <Adafruit_AHTX0.h>
#include <utils.hpp>

class aht20 {
    public:
        aht20(void);
        ~aht20(void);
        void read(void);
        float get_temperature(void);
        float get_humidity(void);
    private:
        Adafruit_AHTX0 _aht;
        float _temperature;
        float _humidity;
};

#endif
