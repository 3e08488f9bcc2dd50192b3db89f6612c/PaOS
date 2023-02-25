#include<memory.h>

void* memset(void* dest, int val, size_t len) {
    unsigned char* d = dest;
    while (len--) *d++ = val;
    return dest;
}

void* memcpy(void *dest, const void *src, size_t len)
{
	char *d = dest;
	const char *s = src;
	while(len--) *d++ = *s++;
	return dest;
}

void* memmove(void *dest, const void *src, size_t len)
{
	char *d = dest;
	char *s = (char*)src;
	if(d < s) while (len--) *d++ = *s++;
	else
	{
		char *lasts = s + (len-1);
		char *lastd = d + (len-1);
		while (len--) *lastd-- = *lasts--;
	}
	return dest;
}

int memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char *s1 = str1;
	const unsigned char *s2 = str2;
	while (len-- > 0)
	{
		if(*s1++ != *s2++) return s1[-1] < s2[-1] ? -1 : 1;
	}
	return 0;
}
