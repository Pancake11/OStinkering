#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"

void kernel_main() {
	isr_install();
	irq_install();

	asm("int $2");
	asm("int $3");
	
	kprint("Type somethin it will go through the kernel\n "
		   " Type END (case sensitive) to halt CPU type PAGE to request a kmalloc\n> ");
}

void user_input(char *input) 
{
	if (strcmp(input, "END") == 0) 
	{
		kprint("Stopping the CPU !\n");
		asm volatile("hlt");
	}
	else if (strcmp(input, "PAGE") == 0) {
		uint32_t phys_addr;
		uint32_t page = kmalloc(1000, 1, &phys_addr);
		char page_str[16] = "";
		hex_to_ascii(page, page_str);
		char phys_str[16] = "";
		hex_to_ascii(phys_addr, phys_str);
		kprint("Page : ");
		kprint(page_str);
		kprint(", physical address : ");
		kprint(phys_str);
		kprint("\n");
	}
	kprint("You said : ");
	kprint(input);
	kprint(" \n> ");
}
