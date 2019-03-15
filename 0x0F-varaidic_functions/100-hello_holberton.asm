section .data
	string db "Hello, Holberton", 0xA

section .text
	global main
main:
	mov rax, 1
	mov rdi, 1
	mov rdx, 17
	mov rsi, string
	syscall
	mov rax, 0
