section .boot
[bits 16]
[global boot]

%define SECTORS 0x6

boot:
	; Enable A20
	mov ax, 0x2401
	int 0x15
	jc a20_failure
	;test ah, ah
	;jnz a20_failure

	call read_disk
	%include "bootloader/GDT.asm"
	call load_gdt
	

read_disk:
	mov [disk], dl
	mov ah, 0x2
	mov al, SECTORS
	mov ch, 0x0      ;cylinder idx
	mov dh, 0x0      ;head idx
	mov cl, 0x2      ;sector idx
	mov dl, [disk] ;disk idx
	mov bx, target_ptr
	int 0x13
	jc disk_failure
ret

a20_failure:
	mov si, a20_error_name
	call bios_print
ret

disk_failure:
	mov si, disk_error_name
	call bios_print
ret

bios_print:
	mov al, [si]
	cmp al, 0
	je halt
	mov ah, 0x0e ; teletype output
	int 0x10
	inc si
	jmp bios_print
ret

halt:
	hlt
	jmp $


disk: db 0
disk_error_name: db '[-] Cannot read disk sectors.', 0
a20_error_name: db '[-] Failed enable the A2O Line.', 0

times 510 - ($-$$) db 0
dw 0xaa55


target_ptr:
%include "bootloader/kernel_entry.asm"
