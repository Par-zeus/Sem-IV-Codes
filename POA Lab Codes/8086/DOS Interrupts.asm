
;Name: Parth Das
; SAPID: 60004220185
; Div: C2-2
; Roll no:C-111

; EXP 10
data segment
MSG DB "Enter a character:$"
data ends

code segment
assume cs:code, ds:data
start:
mov ax,data
mov ds,ax
lea DX, MSG
MOV AH,09h
INT 21H

mov AH,01
int 21H

mov dl,al
mov AH,02
int 21h

mov ah,4ch
int 21h
code ends
end start





