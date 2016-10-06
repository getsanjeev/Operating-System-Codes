global add

add:

push ebp
mov ebp, esp
mov eax, [ebp+8]
mov ebx, [ebp+12]
add eax, ebx
leave
ret