[bits 32]
[extern kmain]

kernel_entry:
	mov esp, krnl_stack_top
	cli
	call kmain
	hlt

section .bss
align 4
krnl_stack_bottom: equ $
resb 16384 ; 16 KB
krnl_stack_top:
