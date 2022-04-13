print_hex:
	pusha
	mov cx, 0 ;index var

hex_loop:
	cmp cx,4
	je end

	mov ax, dx
	mov ax, 0x000f ; 0x1234 ->0x0004 by masking first three to 0
	mov al, 0x30 ;convert to ascii
	cmp al, 0x39 ; if > 9 add 8 to represetn A to F
	jle step2
	add al, 7

step2:
	mov bx, HEX_OUT + 5 ; base + length
	sub bx, cx
	mov [bx], al
	ror dx, 4

	add cx, 1
	jmp hex_loop

end:
	mov bx, HEX_OUT
	call print

	popa
	ret

HEX_OUT:
	db '0x0000',0
