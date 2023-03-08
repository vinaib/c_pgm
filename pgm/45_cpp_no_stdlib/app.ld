/* explore start address */
/* .ARM.extab
 * .ARM.exidx
 * added in object file
 * -fno-exceptions remove above sections
 *
 */

ENTRY(main)

MEMORY
{
   FLASH(rx):ORIGIN = 0x00000000,LENGTH = 1024K
   SRAM(rwx):ORIGIN = 0x20000000,LENGTH = 128K
}

SECTIONS
{
	.text :
   {
      *(.text)
      *(.rodata)
      . = ALIGN(4);
      _etext = .;
   }>FLASH

	.data :
	{
      _sdata = .;
      *(.data)
      . = ALIGN(4);
      _edata = .;
	}>SRAM AT> FLASH /* VMA(virtual Address) AT> LMA (Load address) */

	.bss :
	{
		_sbss = .;
		*(.bss)
		. = ALIGN(4);
		_ebss = .;
   }>SRAM
}
