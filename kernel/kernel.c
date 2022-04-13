#include "../drivers/ports.h"

void main() {
	clear_screen();
	kprint_at("X", 1, 6);
	kprint_at("This text spans multiples lines", 75, 10);
	kprint_at("there is a line\nbreak", -1, 20);
	kprint("There is a line break");
	kprint_at("What happends when we run out of space ?", 45, 24);
}
