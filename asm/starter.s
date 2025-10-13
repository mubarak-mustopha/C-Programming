.section .text
.globl _start

_start:
movl $1, %eax #code for exit sys call
movl $10, %ebx #exit status code
int $0x80 #make a sys call

