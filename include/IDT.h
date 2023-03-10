#ifndef _IDT_H
#define _IDT_H

#include<inttypes.h>
#define IDT_ENTRIES 256

typedef struct {
    uint16_t low_offset; // Lower 16 bits of handler function address
    uint16_t sel; // Kernel segment selector
    uint8_t always0;
    uint8_t flags; 
    uint16_t high_offset; // Higher 16 bits of handler function address
} __attribute__((packed)) idt_gate_t;


typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;


void set_idt_gate(int, uint32_t);
void load_IDT();

#endif // _IDT_H
