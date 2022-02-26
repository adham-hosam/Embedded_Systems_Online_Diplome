/* Linker_script for cortex-m3
author:Adham Hosam
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X08000000 , LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0X20000000 , LENGTH = 20K
}

SECTIONS
{
	.text :{
	
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	} > flash
	
	.data :{
		_S_DATA = .;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = .;
		
	}> SRAM AT> flash
	
	.bss :{
		_S_BSS = .;
		*(.bss*)
		_E_BSS = .;
		. = ALIGN(0x4);
		. = . + 0x1000;
		_stack_top = .;
		
		
	}>SRAM

}