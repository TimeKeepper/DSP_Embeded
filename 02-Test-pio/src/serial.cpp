#include <serial.hpp>

#include <SimpleSerialShell.h>
#include <USBSerial.h>

int hello_world(int argc, char **argv) {
    SerialUSB.println("Hello, world!");
    return 0;
}

void vTask_Serial(void *pvParameters) {
    SerialUSB.begin(115200);

    shell.attach(SerialUSB);

    shell.addCommand(F("sayHello"), hello_world);

    while (1) {
        shell.executeIfInput();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
