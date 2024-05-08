; Name:Parth Das
; SAP ID: 60004220185
; Div: C-22
; Roll No: C-111
; Exp-5

;  Addition

MOV AX,[1000h]
MOV BX,[1002h]
MOV CL,00h
ADD AX,BX
MOV [1004h],AX
JNC jump
INC CL
jump:
MOV [1006h],CL
HLT