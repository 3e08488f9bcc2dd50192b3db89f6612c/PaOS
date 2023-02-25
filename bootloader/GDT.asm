load_gdt:
	cli
	lgdt [gdt_pointer]
	mov eax, cr0
	or eax,0x1
	mov cr0, eax
	call clear_segments
	jmp CODE_SEG:kernel_entry
	
gdt_start:
	dq 0x0

gdt_code:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10011010b
	db 11001111b
	db 0x0

gdt_data:
	dw 0xFFFF
	dw 0x0
	db 0x0
	db 10010010b
	db 11001111b
	db 0x0

gdt_end:


gdt_pointer:
	dw gdt_end - gdt_start
	dd gdt_start
	
clear_segments:
	mov ax, DATA_SEG
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
ret

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
