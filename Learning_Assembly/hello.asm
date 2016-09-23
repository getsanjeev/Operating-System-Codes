SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0


section .text
global_start

_start:

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, usrmsg
mov edx, len_msg
int 80h

section .data
usrmsg db 'Hello:world'
len_msg equ $-usrmsg
