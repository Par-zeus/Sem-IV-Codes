; Name: Parth Das
; Sapid: 60004220185
; Roll no: C-111
; Div: C2-2

; Aim: Block Transfer 

;multi-segment executable file template
data segment
seg1 db 1h,2h,3h
ends
extra segment
seg2 db ?
ends
code segment
start:
;set segment registers:
mov ax, data
mov ds, ax
mov ax, extra
mov es, ax
; add upur code here
lea si, seg1
lea di, seg2
mov cx, 03h
x: mov ah,ds:[si]
mov es: [di],ah

inc si
inc di
dec cx
jnz x

ends
end start 



