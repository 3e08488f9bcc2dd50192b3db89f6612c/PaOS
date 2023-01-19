#ifndef _GDT_H
#define _GDT_H
#include<inttypes.h>

// Variables
struct GDTEntry
{
    uint16_t Limit0; // The lower 16 bits of the limit.
    uint16_t Base0; // The lower 16 bits of the base.
    uint8_t Base1; // Middle (The next bits of the base)
    uint8_t AccessByte; // Access flag
    uint8_t granularity; // low 4 bits are high 4 bits of limit
    uint8_t Base2; // The last 8 bits of the base.
} __attribute__((packed));

struct GDTEntryPointer
{
    uint16_t limit;               // The upper 16 bits of all selector limits.
    uint32_t base;                // The address of the first gdt_entry_t struct.
} __attribute__((packed));

typedef struct GDTEntry gdt_entry_t;
typedef struct GDTEntryPointer gdt_ptr_t;

// Functions
void init_gdt();
gdt_entry_t gdt_set_gate(uint32_t, uint32_t, uint8_t, uint8_t);

// Extern Functions
extern void gdt_write(uint32_t);

#endif // _GDT_H