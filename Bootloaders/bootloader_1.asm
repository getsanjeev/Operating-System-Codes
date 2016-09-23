org 0x7c00
bits 16

global_start
_start:

cli 
hlt
times 510 - ($-$$) db 0

dw 0xAA55
