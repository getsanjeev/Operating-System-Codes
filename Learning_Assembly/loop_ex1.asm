SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0
SYS_EXIT equ 0
SYS_FORK equ 1

segment .bss
temp resb 2

section .text
global _start

_start:

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_1
mov edx, len_1
int 80h

mov eax, 9d
mov [temp], eax
int 80h

my_command:
mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, temp
mov edx, 2
int 80h

sub ecx, 1

cmp ecx, 1
loop my_command

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_2
mov edx, len_2
int 80h

section .data
msg_1 db "The loop starts from 9"
len_1 equ $-msg_1
msg_2 db "Loop completed"
len_2 equ $-msg_2



