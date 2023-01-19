;;;;;;;;;;;;;;; GDT ;;;;;;;;;;;;;;;;;;;;;;
[global gdt_write]

gdt_write:
	mov eax, [esp+4]
	lgdt [eax]
	call clear_segments
ret
	
clear_segments:
	mov ax, 10h
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
ret
;;;;;;;;;;;;;;; GDT_END ;;;;;;;;;;;;;;;;;;;;;;