#ifndef __MEM_HPP__
#define __MEM_HPP__

#include <cstdint>
#include <malloc.h>
#include <utils.hpp>

extern "C" char *sbrk(int i);
/* Use linker definition */
extern char _end;

extern char _ebss;
extern char _sbss;

extern char _edata;
extern char _sdata;

extern char _estack;
extern char _Min_Stack_Size;

const int32_t ramstart = (int32_t)&_sdata;
const int32_t ramend = (int32_t)&_estack;
const int32_t minSP = (int32_t)(ramend) - (int32_t)&_Min_Stack_Size;

const int32_t *stack_ptr = (int32_t *)__get_MSP();

const int32_t data_size = (int32_t)&_edata - (int32_t)&_sdata;
const int32_t bss_size = (int32_t)&_ebss - (int32_t)&_sbss;

#endif
