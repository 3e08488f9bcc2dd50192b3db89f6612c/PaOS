#ifndef _IO_PORTS_H
#define _IO_PORTS_H
#include<inttypes.h>

// In ports
uint8_t inb(uint16_t);
uint16_t inw(uint16_t);
uint32_t inl(uint16_t);

// Out ports
void outb(uint16_t, uint8_t);
void outw(uint16_t, uint16_t);
void outl(uint16_t, uint32_t);

#endif // _IO_PORTS_H