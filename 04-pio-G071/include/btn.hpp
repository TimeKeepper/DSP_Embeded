#ifndef __BTN_HPP__
#define __BTN_HPP__

#include <cstdint>
#include <utils.hpp>
#include <utility>
#include <vector>
#include <atomic>

#define GND false
#define VCC true

#define BTN1 PD8
#define BTN2 PC7

class btn {
public:
    btn(std::vector<std::pair<uint32_t, bool>> btns);
};

extern std::vector<std::unique_ptr<std::atomic<bool>>> btn_states;

#endif