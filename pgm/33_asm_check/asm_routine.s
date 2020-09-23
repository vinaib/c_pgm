.section .text

.globl asm_routine

.type asm_routine, %function

asm_routine:
	stmfd sp!, {r4-r11, lr}
	nop
	ldmfd sp!, {r4-r11, lr}
	bx lr
