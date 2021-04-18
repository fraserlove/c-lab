	.text
	.file	"array.c"
	.globl	contains
	.p2align	4, 0x90
	.type	contains,@function
contains:
	.cfi_startproc
	pushq	%rbp 					# Saving the old base pointer by pushing it to the top of the stack so that the program can return later
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp				# Stack pointer is copied to base pointer so that base pointer points to top of stack
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp				# Decrementing the stack pointer by 48 bytes which will be reserved for local variables for the contains function
	movq	%rdi, -16(%rbp)			# First argument (long* array - 8 bytes) is copied from the rdi register (default register for first argument) to an offset of 16 bytes relative to the base pointer.
	movq	%rsi, -24(%rbp)			# Second argument (long elem - 8 bytes) is copied from the rsi register (default register for second argument) to an offset of 24 bytes relative to the base pointer.
	movl	%edx, -28(%rbp)			# Third argument (int left - 4 bytes) is copied from the edx register (lower 32 bit half of default register for third argument) to an offset of 28 bytes relative to the base pointer.
	movl	%ecx, -32(%rbp)			# Fourth arguement (int right - 4 bytes) is copied from the ecx register (lower 32 bit half of default register for fourth argument) to an offset of 32 bytes relative to the base pointer.
	movl	-32(%rbp), %eax			# The right variable is copied to eax (the lower half of rax).
	subl	-28(%rbp), %eax			# (right - left). The value of left is subtracted from the value of right and the result is kept in eax.
	cmpl	$1, %eax				# Compare the value 1 to the result of (right - left) stored in eax (lower 32 bits or rax).
	jge	.LBB0_2						# Jump to .LBB0_2 branch if (right - left) >= 1 using flags set by compare operation.
	movb	$0, -1(%rbp)			# Copy the value zero (representing false) to an offset of 1 byte relative to the base pointer.
	jmp	.LBB0_8						# Jump to .LB00_8 branch
.LBB0_2:
	movl	-32(%rbp), %eax			# The right variable is copied to eax (the lower half of rax).
	subl	-28(%rbp), %eax			# (right - left). The value of left is subtracted from the value of right and the result is kept in eax.
	cmpl	$1, %eax				# Compare the value 1 to the result of (right - left) stored in eax (lower 32 bits or rax).
	jne	.LBB0_4						# Jump to .LBB0_4 branch if (right - left) == 1 using flags set by compare operation.
	movq	-16(%rbp), %rax			# Copy the value of the pointer called array stored at a 16 byte offset to the base pointer to rax.
	movslq	-28(%rbp), %rcx			# Copy the value of the the left variable stored at a 28 byte offset to the base pointer to rcx. This value is sign extended with 2's complement sign extension.
	movq	(%rax,%rcx,8), %rax		# Copy the value held at (rax + 8 * rcx) to rax (i.e. the value held at array[left] will be moved to rax.) This is because rax holds a pointer to the start of the array. The array is made up of longs (which have a size of 8 bytes). And left holds the index of the array to access.
	cmpq	-24(%rbp), %rax			# Compare the value of the variable elem thats offset from the base pointer by 24 bytes to the value held in rax which is array[left]
	sete	%dl						# Sets dl (the lower 8 bits of rdx) to 1 (true) if the zero flag is set from the comparison (i.e are the same value) and false if otherwise. This returns true when array[left] equals elem and false if otherwise.
	andb	$1, %dl					# Logical and between 1 and the value held in al (result is 0 if value is 0 and 1 if result is 1)
	movb	%dl, -1(%rbp)			# Copy the value held in dl (the lower 8 bits of rdx) a boolean value to the stack at an offset of 1 byte from the base pointer.
	jmp	.LBB0_8						# Jump to .LB00_8 branch
.LBB0_4:
	movl	-28(%rbp), %eax			# The left variable is copied to eax (the lower half of rax).
	movl	-32(%rbp), %ecx			# The right variable is copied to ecx (the lower half or rcx).
	subl	-28(%rbp), %ecx			# (right - left). The value of left is subtracted from the value of right and the result is stored in ecx.
	movl	%eax, -40(%rbp)			# The value of the left variable is copied to the stack at an offset of 40 bytes from the base pointer.
	movl	%ecx, %eax				# The result of (right - left) stored in ecx is moved to eax.
	cltd							# Converts signed long to signed double long so edx is fulled with the most significant bit of eax
	movl	$2, %ecx				# Copies and stores the value 2 into ecx.
	idivl	%ecx					# Divides the value of (right - left) stored in ecx by 2 which is stored in eax and edx. This is the common calling convention. The result stores the quotient in eax and the remainder in edx.
	movl	-40(%rbp), %ecx			# Copys the value of the left variable stored at an offset of 40 bytes from the base pointer to the ecx register.
	addl	%eax, %ecx				# Add up the quotient of (right -left) / 2 stored in eax and the value of the left variable in ecx and stores the result back in ecx.
	movl	%ecx, -36(%rbp)			# Copies the result of left + (right - left) / 2 (now the variable called mid) onto the stack at an offset of 36 bytes from the base pointer.
	movq	-24(%rbp), %rsi			# Copies the value in the elem variable to rsi
	movq	-16(%rbp), %rdi			# Copies the value in the array pointer to rdi
	movslq	-36(%rbp), %r8			# Copies the value of mid held at an offset of 36 bytes in the stack to the register r8. This value is sign extended with 2's complement sign extension.
	cmpq	(%rdi,%r8,8), %rsi		# Compare the value held at (rdi + 8 * r8) (i.e. the value held at array[mid] since r8 holds the value of mid) to the value of the variable elem held in rsi.
	jge	.LBB0_6						# Jump to .LBB0_6 branch if elem >= array[mid] using flags set by compare operation.
	movq	-16(%rbp), %rdi			# Copies the value in the array pointer to rdi
	movq	-24(%rbp), %rsi			# Copies the value in the elem variable to rsi
	movl	-28(%rbp), %edx			# Copies the value of the left variable to edx
	movl	-36(%rbp), %ecx			# Copies the value of the mid variable still stored at an offset of 36 bytes in the stack relative to the base pointer to ecx
	callq	contains				# Recursive call to contains function, with 4 arguments in rdi, rsi, edx (rdx) and ecx (rcx) to adhere to calling convention. After this recursive call has finished the return value will be stored in rax.
	andb	$1, %al					# Logical and between 1 and the value held in al (lower byte if rax) which is the boolean return value from the recursive call to contains (result is 0 if value is 0 and 1 if result is 1)
	movzbl	%al, %ecx				# Copy the zero extended byte in the register al to eax (the lower 32 bits of rax, the default return register by calling convention)
	movl	%ecx, -44(%rbp)			# Copy the value just placed in ecx (the boolean return value) to an offset of 44 bytes from the base pointer on the stack.
	jmp	.LBB0_7						# Jump to .LB00_7 branch
.LBB0_6:
	movq	-16(%rbp), %rdi			# Copies the value in the array pointer to rdi
	movq	-24(%rbp), %rsi			# Copies the value in the elem variable to rsi
	movl	-36(%rbp), %edx			# Copies the value of the mid variable still stored at an offset of 36 bytes in the stack relative to the base pointer to edx.
	movl	-32(%rbp), %ecx			# Copies the value in the right variable to ecx.
	callq	contains				# Recursive call to contains function, with 4 arguments in rdi, rsi, edx (rdx) and ecx (rcx) to adhere to calling convention. After this recursive call has finished the return value will be stored in rax.
	andb	$1, %al					# Logical and between 1 and the value held in al (lower byte if rax) which is the boolean return value from the recursive call to contains (result is 0 if value is 0 and 1 if result is 1)
	movzbl	%al, %ecx				# Copy the zero extended byte in the register al to eax (the lower 32 bits of rax, the default return register by calling convention)
	movl	%ecx, -44(%rbp)			# Copy the value just placed in ecx (the boolean return value) to an offset of 44 bytes from the base pointer on the stack.
.LBB0_7:
	movl	-44(%rbp), %eax			# Copy the value at the offset of 44 bytes from the base pointer in the stack (the boolean return value) to eax (the lower 32 bits of rax).
	cmpl	$0, %eax				# Compare the value 0 to the boolean return value held in eax.
	setne	%cl						# Set register cl = 1 if 0 is not equal to the return value.
	andb	$1, %cl					# Logical and between 1 and the value held in al which is the boolean return value (result is 0 if value is 0 and 1 if result is 1)
	movb	%cl, -1(%rbp)			# Move the value in cl value to the stack at an offset of one byte from the base pointer.
.LBB0_8:
	movb	-1(%rbp), %al			# Copy the value held at an offset of one byte from the base pointer (the boolean value to be returned) to al (the lower byte of rax)
	andb	$1, %al					# Logical and between 1 and the value held in al which is the boolean return value (result is 0 if value is 0 and 1 if result is 1)
	movzbl	%al, %eax				# Copy the zero extended byte in the register al to eax (the lower 32 bits of rax, the default return register by calling convention)
	addq	$48, %rsp				# Stack pointer is set to the value it was before allocating space for the contains function
	popq	%rbp					# Base pointer is restored to previous value before contains function was called
	.cfi_def_cfa %rsp, 8
	retq							# Pops the address from the stack where the next instruction resides and puts it into rip (instruction register)
.Lfunc_end0:
	.size	contains, .Lfunc_end0-contains
	.cfi_endproc

	.ident	"clang version 10.0.1 (Red Hat 10.0.1-1.module_el8.3.0+467+cb298d5b)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym contains
