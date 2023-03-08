	.arch armv7-a
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"check.c"
	.text
	.global	glbVar
	.data
	.align	2
	.type	glbVar, %object
	.size	glbVar, 4
glbVar:
	.word	100
	.global	glbVar2
	.align	2
	.type	glbVar2, %object
	.size	glbVar2, 4
glbVar2:
	.word	200
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.fpu vfpv3-d16
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	movw	r3, #:lower16:glbVar
	movt	r3, #:upper16:glbVar
	ldr	r3, [r3]
	add	r2, r3, #500
	movw	r3, #:lower16:glbVar
	movt	r3, #:upper16:glbVar
	str	r2, [r3]
	movs	r3, #0
	mov	r0, r3
	mov	sp, r7
	@ sp needed
	ldr	r7, [sp], #4
	bx	lr
	.size	main, .-main
	.ident	"GCC: (Linaro GCC 7.5-2019.12) 7.5.0"
	.section	.note.GNU-stack,"",%progbits
