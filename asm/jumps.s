.global _start

.section .text
_start:
  movl $1, %eax    # exit sys call
  movl $10, %ebx   # store 10 as initial exit status code
  movl $9, %ecx    
  cmpl %ecx, %ebx
  jge endblock     #if content ebx >= ecx, transfer control to endblock
  movl $0, %ebx    #otherwise set exit status to 0
endblock:
  int $0x80        
