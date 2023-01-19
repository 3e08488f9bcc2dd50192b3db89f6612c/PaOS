#ifndef _MEMORY_H
#define _MEMORY_H
#include<inttypes.h>

void* memset(void*, int, size_t);
void* memcpy(void*, const void*, size_t);
void* memmove(void*, const void*, size_t);
int memcmp(const void*, const void*, size_t);


#endif // _MEMORY_H