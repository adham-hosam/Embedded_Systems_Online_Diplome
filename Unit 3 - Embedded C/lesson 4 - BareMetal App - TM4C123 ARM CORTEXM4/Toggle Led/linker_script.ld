/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		 Linker Script Cortex M4	***************/
/**************************************************************/
/**************************************************************/


MEMORY
{
    flash(RX) : ORIGIN = 0X00000000, LENGTH = 512M  /* Flash memory region (read-execute) */
    SRAM(RWX) : ORIGIN = 0X20000000, LENGTH = 512M   /* SRAM (Static RAM) region (read-write-execute) */
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata*)
        _E_text = .; 	/* Define the end of the .text section */
    } > flash

	.debug :
	{
		*(.debug*)
	}

    .data :
    {
        _S_DATA = .; /* Define the start of the .data section */
        *(.data*)
        . = ALIGN(4); /* Align data to 4-byte boundary */
        _E_DATA = .; /* Define the end of the .data section */
    } > SRAM AT> flash /* Data is placed in SRAM but linked to the flash region */

    .bss :
    {
        _S_BSS = .; /* Define the start of the .bss section */
        *(.bss*)
        _E_BSS = .; /* Define the end of the .bss section */
        . = ALIGN(0x4); /* Align to 4-byte boundary */
        . = . + 0x1000; /* Reserve 0x1000 bytes for the stack */
        _stack_top = .; /* Define the end of the stack space */
    } > SRAM /* .bss data is placed in SRAM */
}
