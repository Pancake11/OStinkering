#ifndef MEM_H
#define MEM_H

#include <stdint.h>
#include <stddef.h>

//no free implemented yet
uint32_t kmalloc(size_t size, int align, uint32_t *phys_addr);
void* memmove(void* dstptr, const void* srcptr, size_t size);
int memcmp(const void* aptr, const void* bptr, size_t size);
void* memset(void* bufptr, int value, size_t size);
void* memcpy(void* dstptr, const void* srcptr, size_t size);
#endif
