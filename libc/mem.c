#include "mem.h"

void memory_copy(uint8_t *source, uint8_t *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(uint8_t *dest, uint8_t val, uint32_t len) {
    uint8_t *temp = (uint8_t *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

//should be computed at link time but will be hardcoded for now
uint32_t free_mem_addr = 0x10000;

//just a pointer that points to a memory that keeps growing
uint32_t kmalloc(size_t size, int align, uint32_t *phys_addr) {
	//pages are aligned to 4k or 0x10000
	if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
		free_mem_addr &= 0xFFFFF000;
		free_mem_addr += 0x10000;
	}
	//also saving the physical address
	if (phys_addr) *phys_addr = free_mem_addr;

	uint32_t ret = free_mem_addr;
	free_mem_addr += size;
	return ret;
}

/*-------------------- memory kernel api ----------------*/
/*	OSdev wiki meaty skeleton implementation regrouped in one file*/

void* memmove(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	size_t i;
	if (dst < src) {
		for (i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}

int memcmp(const void* aptr, const void* bptr, size_t size) {
	const unsigned char* a = (const unsigned char*) aptr;
	const unsigned char* b = (const unsigned char*) bptr;
	size_t i;
	for (i = 0; i < size; i++) {
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return 1;
	}
	return 0;
}

void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	size_t i;
	for (i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}

void* memcpy(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	size_t i;
	for (i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}
