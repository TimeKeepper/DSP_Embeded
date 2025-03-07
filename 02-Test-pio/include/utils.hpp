#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <Arduino.h>
#include <memory>
#include <vector>
#include <functional>

#include <FreeRTOS.h>
#include <task.h>

extern std::vector<std::unique_ptr<std::atomic<bool>>> btn_states;

#endif
