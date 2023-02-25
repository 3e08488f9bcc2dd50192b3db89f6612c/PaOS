ENTRY(boot)
OUTPUT_FORMAT("binary")
SECTIONS {
    . = 0x7c00; /* address */
    .text : {
        *(.boot)
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
}
