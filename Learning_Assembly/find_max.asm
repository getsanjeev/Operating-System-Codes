SYS_WRITE equ 4
SYS_READ equ 3
STDOUT equ 1
STDIN equ 0
SYS_EXIT equ 0
SYS_FORK equ 1

segment .bss
input_1 resb 2
input_2 resb 2
input_3 resb 2
max resb 2

section .text

; TAKING INPUT FROM USER-----------------

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

mov eax, SYS_READ
mov ebx, STDIN
mov ecx, input_3
mov edx, 2
int 80h

;PRINTING THE SUM STATEMENT---------------------

mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, msg_4
mov edx, len_4
int 80h

; MAKING OUT COMPARISONS---------------------------

mov ecx, input_1
cmp ecx, input_2
jg third_one 
mov ecx, input_2
int 80h

third_one:
cmp ecx, input_3
jg print
mov ecx, input_3
int 80h

print:
mov [max], ecx
mov eax, SYS_WRITE
mov ebx, STDOUT
mov ecx, max
mov edx, 2
int 80h
 
section .data

msg_1 db "Enter the first number"
len_1 equ $-msg_1
msg_2 db "Enter the second number"
len_2 equ $-msg_2
msg_3 db "Enter the third number"
len_3 equ $-msg_3
msg_4 db "The Maximum is : "
len_4 equ $-msg_4



















