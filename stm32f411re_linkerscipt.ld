/*
VMA - virtual memory address
LMA - load memory address
Location counter tracks VMA
*/

/* Define application entry point */
ENTRY(Reset_Handler)

/* Describe memory layout */
MEMORY
{
  SRAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
  FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 512K
}


/* Symbols */



/* Create output sections in the executable, order is important */
/* Use location counter (.) */
SECTIONS 
{
    /*.text section will merge all .isr_vector, .text and .rodata sections of all input files*/
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.text.*)
        *(.init)
        *(.fini)
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);   /* Align location counter to word boundary */
        _etext = .;    /* Store updated location counter value in a symbol in order to catch section boundaries */
    }> FLASH

    _la_data = LOADADDR(.data); /* Load address of data section */

    .data :
    {
        _sdata = .; /* Store location pointer which points to start of VMA section */
        *(.data)
        *(.data.*)
        . = ALIGN(4);   /* Align location counter to word boundary */
        _edata = .;
    } >SRAM AT> FLASH

    .bss :
    {
        _sbss = .; 
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(4);   /* Align location counter to word boundary */
        _ebss = .;
        __bss_end__ = _ebss;
        . = ALIGN(4);
        end = .;
        __end__ = .;
    }> SRAM
}