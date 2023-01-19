#include<GDT.h>
const unsigned int values[4] = {0x9A, 0x92, 0xFA, 0xF2}; /// 8

gdt_entry_t gdt_set_gate(uint32_t base, uint32_t lim, uint8_t access, uint8_t gran)
{
	gdt_entry_t gdt_entry;
	gdt_entry.Base0 = (base & 0xFFFF);
	gdt_entry.Base1 = (base >> 16) & 0xFF;
	gdt_entry.Base2 = (base >> 24) & 0xFF;
	
	gdt_entry.Limit0 = (lim & 0xFFFF);
	gdt_entry.granularity = (lim >> 16) & 0x0F;
	
	gdt_entry.granularity |= gran & 0xF0;
	gdt_entry.AccessByte = access;
	return gdt_entry;
}

void init_gdt()
{
	gdt_entry_t gdt_entries[5];
	gdt_ptr_t gdt_ptr;
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base  = (uint32_t)&gdt_entries;
	gdt_entries[0] = gdt_set_gate(0, 0, 0, 0); // NULL
	for(int i = 1; i < 5; i++)
	{
		gdt_entries[i] = gdt_set_gate(0, 0xFFFFFFFF, values[i-1], 0xCF);
	}
	gdt_write((uint32_t)&gdt_ptr);
}