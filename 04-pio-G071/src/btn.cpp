#include "WInterrupts.h"
#include "wiring_constants.h"
#include <atomic>
#include <btn.hpp>
#include <memory>

std::vector<std::unique_ptr<std::atomic<bool>>> btn_states;

static std::vector<std::function<void(void)>> _interrupts;

btn::btn(std::vector<std::pair<uint32_t, bool>> btns) {
    uint32_t index = 0;
    for (auto btn : btns) {
        btn_states.push_back(std::make_unique<std::atomic<bool>>(false));
        _interrupts.push_back([index]() {
            btn_states[index]->store(true);
        });

        pinMode(btn.first, 
            btn.second ? INPUT_PULLDOWN : INPUT_PULLUP);

        attachInterrupt(btn.first, _interrupts[index], 
            btn.second ? RISING : FALLING);

        index++;
    }
}
