#include<Ports.h>

// In ports
uint8_t inb(uint16_t port) // byte
{
    uint8_t res;
    asm volatile("inb %1, %0" : "=a" (res) : "dN" (port));
    return res;
}

uint16_t inw(uint16_t port) // word
{
    uint16_t res;
    asm volatile ("inw %1, %0" : "=a" (res) : "dN" (port));
    return res;
}
 
uint32_t inl(uint16_t port)
{
    uint32_t res;
    asm volatile ("inl %1, %0" : "=a" (res) : "dN" (port));
    return res;
}

// Out ports
void outb(uint16_t port, uint8_t data) // byte
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (data));
}

void outw(uint16_t port, uint16_t data) // word
{
    asm volatile ("outw %1, %0" : : "dN" (port), "a" (data));
}

void outl(uint16_t port, uint32_t data)
{
    asm volatile ("outl %1, %0" : : "dN" (port), "a" (data));
}