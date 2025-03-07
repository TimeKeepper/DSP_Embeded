#ifndef __BTN_HPP__
#define __BTN_HPP__

#include <cstdint>
#include <utils.hpp>
#include <utility>
#include <vector>

#define GND false
#define VCC true

class btn {
public:
    btn(std::vector<std::pair<uint32_t, bool>> btns);
    static std::vector<std::function<void(void)>> _interrupts;
};

#endif