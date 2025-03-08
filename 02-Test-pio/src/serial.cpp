#include <atomic>
#include <serial.hpp>
#include <SimpleSerialShell.h>
#include <USBSerial.h>
#include <string>
#include <unordered_map>
#include <vector>

void PRINT (const __FlashStringHelper *a, int b = -1, const __FlashStringHelper * c = NULL)
{
    shell.print(a);
    if (b != -1) {
        shell.print(F("0x"));
        shell.print(b,HEX);
        if (c) {
            shell.print(c);
        }
    }
    shell.println();
}

int hello_world(int argc, char **argv) {
    SerialUSB.print("Hello, ");

    auto lastArg = argc - 1;
    for (int i = 1; i < argc; i++) {
        shell.print(argv[i]);

        if (i < lastArg)
            shell.print(F(" "));
    }

    if (argc == 1) {
        shell.print(F("World"));
    }

    shell.println("!");

    return 0;
}

#include <Mem.hpp>

int segment(int argc, char **argv) {
    struct mallinfo mi = mallinfo();

    char *heapend = (char*)sbrk(0);
    int heap_end 	= 	(int)heapend;
    int	heap_size	=	heap_end - (int)&_ebss;

    int	stack_size	=	(int)_Min_Stack_Size;
    int	available	=	(int)&ramend - (int)&ramstart;

    available	-=	data_size + bss_size + heap_size + stack_size;

    PRINT( F( "+----------------+ " ),        (int)_sdata,  F(" (__data_start)"));
    PRINT( F( "+      data      +" ));
    PRINT( F( "+    variables   + size = " ), data_size);
    PRINT( F( "+----------------+ " ),        (int)&_edata, F(" (__data_end / __bss_start)"));
    PRINT( F( "+      bss       +" ));
    PRINT( F( "+    variables   + size = " ), bss_size);
    PRINT( F( "+----------------+ " ),        (int)&_ebss,  F(" (__bss_end / __heap_start)"));
    PRINT( F( "+      heap      + size = " ), heap_size);
    PRINT( F( "+----------------+ " ),        (int)heap_end,    F(" (__brkval if not 0, or __heap_start)"));
    PRINT( F( "+                +" ));
    PRINT( F( "+                +" ));
    PRINT( F( "+   FREE RAM     + size = " ), available);
    PRINT( F( "+                +" ));
    PRINT( F( "+                +" ));
    PRINT( F( "+----------------+ " ),        (int)minSP,   F(" (SP)"));
    PRINT( F( "+     stack      + size = " ), stack_size);
    PRINT( F( "+----------------+ " ),        (int)&ramend, F(" (RAMEND / __stack)"));
    shell.println();
    shell.println();

    return 0;
}

#include <ADC.hpp>

Adc adc;

int read(int argc, char **argv) {
    std::vector<std::string> args(argv + 1, argv + argc);

    const std::unordered_map<std::string, std::function<void(std::vector<std::string>)>> handlers = {
        {"b", [](std::vector<std::string> args) {
            for(auto& btn_state : btn_states) {
                PRINT(F("Button state: "), btn_state->load());
            }
        }},

        {"a", [](std::vector<std::string> args) {
            switch(args[0][0]){
                case 'v':
                    shell.print(F("ADC voltage: "));
                    shell.println(adc.read_voltage());
                    break;
                case 'r':
                    shell.print(F("ADC raw: "));
                    shell.println(adc.read());
                    break;
                default:
                    return;
            }
        }}
    };

    auto it = handlers.find(args[0]);
    if (it != handlers.end()) {
        args.erase(args.begin());
        it->second(args);
    }

    return 0;
}

void vTask_Serial(void *pvParameters) {
    SerialUSB.begin(115200);

    shell.attach(SerialUSB);

    shell.addCommand(F("sayHello"), hello_world);
    shell.addCommand(F("segment"), segment);
    shell.addCommand(F("r"), read);

    while (1) {
        shell.executeIfInput();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
