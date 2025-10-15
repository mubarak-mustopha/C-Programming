.globl _start

.section .data

_start:
	pushl $5
	push $2
	call power
	movl %eax, %ebx
	movl $1, %eax
	int $0x80
.type power, @function
power:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %ebx
	movl 12(%ebp), %ecx
	movl %ebx, %eax 
loop:
	cmpl $1, %ecx
	je power_end
	imull %ebx, %eax
	decl %ecx
	jmp loop
power_end:
	movl %ebp, %esp
	popl %ebp
	ret
