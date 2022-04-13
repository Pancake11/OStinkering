[bits 32]
[extern main] ;define calling point. Must have same name as kernel.c main
call main
jmp $
