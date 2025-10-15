.global _start

.section .text
_start:
 movl $1, %eax
 movl $0, %ebx
 movl $10, %ecx

loop:
 incl %ebx
 decl %ecx

end:
 cmpl $0, %ecx
 jg loop

 int $0x80
