    section .data
greet:	db "Hello, Holberton",10,0
format_specifier:	db "%s",0

    section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    mov rsi, greet
    mov rdi, format_specifier
    call printf

    pop rbp
    mov rax, 0
    ret
