#include <atomic>
#include <serial.hpp>
#include <SimpleSerialShell.h>
#include <USBSerial.h>

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
    for ( int i = 1; i < argc; i++) {

        shell.print(argv[i]);

        if (i < lastArg)
            shell.print(F(" "));
    }

    shell.println("!");

    return 0;
}

#include <malloc.h>
extern "C" char *sbrk(int i);
/* Use linker definition */
extern char _end;

extern char _ebss;
extern char _sbss;

extern char _edata;
extern char _sdata;

extern char _estack;
extern char _Min_Stack_Size;

static char *ramstart = &_sdata;
static char *ramend = &_estack;
static char *minSP = (char*)(ramend - &_Min_Stack_Size);

int segment(int argc, char **argv) {
    char *heapend = (char*)sbrk(0);
    char * stack_ptr = (char*)__get_MSP();
    struct mallinfo mi = mallinfo();

    int	data_size	=	(int)&_edata - (int)&_sdata;
    int	bss_size	=	(int)&_ebss - (int)&_sbss;
    int heap_end 	= 	(int)heapend;
    
    int	heap_size	=	heap_end - (int)&_ebss;
    int	stack_size	=	_Min_Stack_Size;
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

int show(int argc, char **argv) {
    for(auto& btn_state : btn_states) {
        PRINT(F("Button state: "), btn_state->load());
    }
    return 0;
}

void vTask_Serial(void *pvParameters) {
    SerialUSB.begin(115200);

    shell.attach(SerialUSB);

    shell.addCommand(F("sayHello"), hello_world);
    shell.addCommand(F("segment"), segment);
    shell.addCommand(F("show"), show);

    while (1) {
        shell.executeIfInput();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}
