SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0
SYS_EXIT equ 0
SYS_FORK equ 1

section .text
global_start;

_start:

mov eax, 8
mov ebx, file_name
mov ecx, 777
int 80h

mov [fd_out], eax

mov eax, SYS_WRITE
mov ebx, [fd_out]
mov ecx, msg
mov edx, len_msg
int 80h

mov eax, 6
mov ebx, [fd_out]

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_2
mov edx, len_msg_2
int 80h


mov eax, 5
mov ebx, file_name
mov ecx, 0
mov edx, 777
int 80h

mov [fd_in], eax

mov eax, 3
mov ebx, [fd_in]
mov ecx, info
mov edx, 26
int 80h

mov eax, 6
mov ebx, [fd_in]

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_3
mov edx, len_msg_3
int 80h

xor eax, eax
xor ebx, ebx
xor ecx, ecx
xor edx, edx

mov eax, 1
int 80h

section .data

file_name db 'pankaj.txt'
msg db 'Welcome to the real world'
len_msg equ $-msg

msg_2 db 'Now reading the file'
len_msg_2 equ $-msg_2

msg_3 db 'good bye'
len_msg_3 equ $-msg_3

section .bss

fd_out resb 1
fd_in resb 1
info resb 26






