.globl _start

.section .text
_start:
main:
	pushl $20       # push second arg on the stack
	pushl $10       # push first arg on the stack
	call add_nums     
	addl $8, %esp    # reset stack

	# get return value and exit 
	movl %eax, %ebx  # copy return value from %eax into %ebxx
	movl $1, %eax    # set up for exit sys call
	int $0x80

.type add_nums, @function
add_nums:
	pushl %ebp           # push content of %ebp on stack
	movl %esp, %ebp	     # make %ebp equals %esp

	movl 8(%ebp), %eax   # copy first arg into %eax
	movl 12(%ebp), %ebx  # copy 2nd arg into %ebx

	# function logic
	addl %ebx, %eax

	# restore stack before returning
	movl %ebp, %esp     # restore stack pointer 
	popl %ebp	    # restore base pointer	
	ret
