#include <AHT20.hpp>

aht20::aht20(void) {
    Wire.setSCL(PB13);
    Wire.setSDA(PB14);

    Wire.begin();

    // _aht.begin(&Wire);
}

aht20::~aht20(void) {
}

void aht20::read(void) {
    sensors_event_t humidity, temp;
  
    _aht.getEvent(&humidity, &temp);
    
    _temperature = temp.temperature;
    _humidity = humidity.relative_humidity;
}

float aht20::get_temperature(void) {
    return _temperature;
}

float aht20::get_humidity(void) {
    return _humidity;
}
