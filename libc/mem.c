#include "mem.h"

void memory_copy(u8 *source, u8 *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len) {
    u8 *temp = (u8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

//should be computed at link time but will be hardcoded for now
u32 free_mem_addr = 0x10000;

//just a pointer that points to a memory that keeps growing
u32 kmalloc(u32 size, int align, u32 *phys_addr) {
	//pages are aligned to 4k or 0x10000
	if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
		free_mem_addr &= 0xFFFFF000;
		free_mem_addr += 0x10000;
	}
	//also saving the physical address
	if (phys_addr) *phys_addr = free_mem_addr;

	u32 ret = free_mem_addr;
	free_mem_addr += size;
	return ret;
}
