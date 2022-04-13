mov ah, 0x0e

;attempt 1
;fails and prints memory address
mov al, "1"
int 0x10
mov al, the_secret
int 0x10

;attempt 2
;fails bcs bios will place our boot sector at pos 0x7c00
;right approach tho
mov al, "2"
int 0x10
mov al, [the_secret]
int 0x10

;attempt 3
;adding the 0x7c00 bios offset to the address of the_secret
;dereferences the content of the pointere
mov al, "3"
int 0x10
mov bx, the_secret
add bx, 0x7c00
mov al, [bx]
int 0x10

;attempt 4
;trying shortcut bcs the_secret is stored at pos 0x2d in our bin
mov al, "4"
int 0x10
mov al, [0x7c2d]
int 0x10

jmp $

the_secret:
	db "X"

times 510-($-$$) db 0
dw 0xaa55
