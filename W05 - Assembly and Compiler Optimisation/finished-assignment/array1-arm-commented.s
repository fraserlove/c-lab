	.text
	.file	"array.c"
	.globl	contains
	.p2align	2
	.type	contains,@function
contains:
	.cfi_startproc
	stp	x29, x30, [sp, #-16]!			# Store x29 (FP) and x30 (LR) at [sp-16] on the stack and subtract 16 from sp
	mov	x29, sp							# x29 = sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	sub	w8, w3, w2						# w8 = right - left
	cmp	w8, #1							# Compare w8 (right - left) to 1
	b.lt	.LBB0_3						# Branches to .LBB0_3 if (right - left) < 1
	b.ne	.LBB0_4						# Branches to .LBB0_4 if (right - left) != 1
	ldr	x8, [x0, w2, sxtw #3]			# x8 = array[left] using: addr = x0 + w2 * (2**3 = 8) = *array + left * 8
	cmp	x8, x1							# Compare x8 (array[left]) to elem
	cset	w0, eq						# Sets w0 to 1 if array[left] == elem and 0 if not
	b	.LBB0_8							# Branches to .LBB0_8
.LBB0_3:
	mov	w0, wzr							# w0 = wzr (zero register) i.e. w0 = 0
	b	.LBB0_8							# Branches to .LBB0_8
.LBB0_4:
	cmp	w8, #0							# Compare w8 (right - left) to 0
	cinc	w8, w8, lt					# (right - left)++ if (right - left) < 0
	add	w8, w2, w8, asr #1				# w8 = mid = left + (right - left) / 2
	ldr	x9, [x0, w8, sxtw #3]			# x9 = array[mid] using: addr = x0 + w8 * (2**3 = 8) = *array + mid * 8
	cmp	x9, x1							# Compare array[mid] to elem
	b.le	.LBB0_6						# Branches to .LBB0_6 if array[mid] <= elem
	mov	w3, w8							# right = mid
	b	.LBB0_7							# Branches to .LBB0_7
.LBB0_6:
	mov	w2, w8							# left = mid
.LBB0_7:
	bl	contains						# Branch with link to contains
.LBB0_8:
	and	w0, w0, #0x1					# w0 = w0 && 1 = w0 (Bitwise AND), w0 is boolean return value by calling convention
	ldp	x29, x30, [sp], #16				# Restores x29 (FP) and x30 (LR) registers held at [sp-16] on the stack 
	ret									# Return to caller
.Lfunc_end0:
	.size	contains, .Lfunc_end0-contains
	.cfi_endproc

	.ident	"clang version 10.0.1 (Red Hat 10.0.1-1.module_el8.3.0+467+cb298d5b)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
