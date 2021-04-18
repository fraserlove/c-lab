	.text
	.file	"array.c"
	.globl	contains
	.p2align	4, 0x90
	.type	contains,@function
contains:
	.cfi_startproc
	jmp	.LBB0_1 					# Jump to .LB00_7 branch
	.p2align	4, 0x90
.LBB0_7:
	movl	%r8d, %edx				# Copy the value of mid (left + (right - left) / 2) into rdx (replacing the old left value)
.LBB0_1:
	movl	%ecx, %r8d				# Copy the value of right stored in ecx (by calling convention) and store in r8d (the lower 32 bits of r8)
	subl	%edx, %r8d				# Subtract the value of right now stored in r8d with the value of left stored in edx (by calling convention) and store result back into r8d.
	jle	.LBB0_8						# Jump to .LBB0_8 if from the subtraction, the value of right (r8d) was less than or equal to the value of left (edx)
.LBB0_3:
	cmpl	$1, %r8d				# Compare the value 1 with the value (right - left) stored in r8d
	je	.LBB0_4						# Jump to .LBB0_4 if 1 == (right - left) from comparison
	shrl	%r8d					# Shifts the value in r8d to the right by one bit, setting the higher-order bit to 0. This in effect, divides the value by 2.
	addl	%edx, %r8d				# Adds the value of left stored in edx to the r8d storing (right - left) / 2
	movslq	%r8d, %rax				# Copies the value of mid (left + (right - left) / 2) into rax with 2's complement sign extension to convert to 64 bits.
	cmpq	%rsi, (%rdi,%rax,8)		# Compare the value elem held in rsi with array[mid] (since (rdi + 8 * rax), rdi is a pointer to the start of the array and 8 * rax accesses the specific index in the array.)
	jle	.LBB0_7						# Jump to .LBB0_8 if from the comparison, the value of array[mid] was less than or equal to the variable elem
	movl	%r8d, %ecx				# Copy the value of mid (left + (right - left) / 2) into ecx (the lowest 32 bits of rdx)
	subl	%edx, %r8d				# Subtract the value of mid stored in r8d with the value of left stored in edx and store result back in r8d.
	jg	.LBB0_3						# Jump to .LBB0_3 if from the subtraction, the value of mid (r8d) was less greater than to the value of left (edx)
.LBB0_8:
	xorl	%eax, %eax				# Zeros the return register eax (the lower half of rax) which represents false.
	retq							# Pops the address from the stack where the next instruction resides and puts it into rip (instruction register)
.LBB0_4:
	movslq	%edx, %rax				# Copies the value of left stored in edx into rax with 2's complement sign extension to convert to 64 bits.
	cmpq	%rsi, (%rdi,%rax,8)		# Compare the value of elem in rsi with array[mid] (since (rdi + 8 * rax), rdi is a pointer to the start of the array and 8 * rax accesses the specific index in the array.)
	sete	%al						# Sets al (the lower 8 bits of rax) to 1 (true) if the zero flag is set from the comparison (i.e are the same value) and false if otherwise. This returns true when array[mid] equals elem and false if otherwise.
	retq							# Pops the address from the stack where the next instruction resides and puts it into rip (instruction register).
.Lfunc_end0:
	.size	contains, .Lfunc_end0-contains
	.cfi_endproc

	.ident	"clang version 10.0.1 (Red Hat 10.0.1-1.module_el8.3.0+467+cb298d5b)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
