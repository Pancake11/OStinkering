#include "../drivers/ports.h"
#include "utils.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

void main() {
	isr_install();

	//testing int
	__asm__ __volatile__("int $2");
	__asm__ __volatile__("int $3");
}
