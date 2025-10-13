starter: starter.out
	ld -m elf_i386 starter.out -o starter
starter.out: starter.s
	as -32 starter.s -o starter.out

hello: hello.out
	ld -m elf_i386 hello.out -o hello
hello.out: hello.s
	as -32 hello.s -o hello.out
jumps: jumps.out
	ld -m elf_i386 jumps.out -o jumps
jumps.out: jumps.s
	as -32 jumps.s -o jumps.out
