SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0
SYS_EXIT equ 0
SYS_FORK equ 1

section .text
global _start

_start:

mov eax, 4h
and eax, 1
jz even_f
mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_odd
mov edx, len_odd
int 80h

even_f:
mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_even
mov edx, len_even
int 80h


section .data
msg_even db "EVEN NUMBER"
len_even equ $-msg_even

msg_odd db "ODD NUMBER"
len_odd equ $-msg_odd

