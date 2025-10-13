.global _start

.section .data
msg:
  .ascii "Hello World!\n"

.section .text
_start:
  movl $4, %eax   # set eax up for write syscall
  movl $1, %ebx   # set fd to 1 for stdout
  movl $msg, %ecx # set buffer address
  movl $13, %edx  # set buffer size
  int $0x80       # make sys call

# call exit syscall with successfull exit code
  movl $1, %eax
  movl $0, %ebx
  int $0x80
