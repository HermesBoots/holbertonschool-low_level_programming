section .data
	fmt: db "%s", 10, 0
	str: db "Hello, Holberton", 0
	extern printf
	global main
section .text
main:
	mov rdi, fmt
	mov rsi, str
	push rbp
	call printf
	pop rbp
	mov rax, 0
