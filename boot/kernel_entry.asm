global _start ;
[bits 32]

_start:
	[extern kernel_main] ;define calling point. Must have same name as kernel.c main
	call kernel_main
	jmp $
