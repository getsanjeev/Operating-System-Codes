SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0
SYS_EXIT equ 0
SYS_FORK equ 1

segment .bss
input_1 resb 2
input_2 resb 2
sum resb 2

section .text
global_start
_start:

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_1
mov edx, len_1
int 80h

mov eax, SYS_READ
mov ebx, STDIN
mov ecx, input_1
mov edx, 2
int 80h

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_2
mov edx, len_2
int 80h

mov eax, SYS_READ
mov ebx, STDIN
mov ecx, input_2
mov edx, 2
int 80h


mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_3
mov edx, len_3
int 80h

mov eax, [input_1]
sub eax, '0'
mov ebx, [input_2]
sub ebx, '0'

add eax, ebx
add eax, '0'
mov [sum], eax

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, sum
mov edx, 1
int 80h


section .data

msg_1 db "Enter the first digit"
len_1 equ $-msg_1
msg_2 db "Enter the second digit"
len_2 equ $-msg_2
msg_3 db "The sum is : "
len_3 equ $-msg_3
















