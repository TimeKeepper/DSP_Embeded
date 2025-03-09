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

const uint32_t ramstart = (uint32_t)&_sdata;
const uint32_t ramend = (uint32_t)&_estack;
const uint32_t minSP = (uint32_t)(ramend) - (uint32_t)&_Min_Stack_Size;

const uint32_t *stack_ptr = (uint32_t *)__get_MSP();

const uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
const uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;

#endif
