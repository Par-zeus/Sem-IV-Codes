
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt



; Name :Parth Das
; Sapid: 60004220185
; Roll no: C-111
; Div: C-22    


DATA SEGMENT
STRING1 DB 99H,12H,56H,45H,36H
DATA ENDS



CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
MOV DS,AX

MOV CH,04

UP2:MOV CL,04H
LEA SI,STRING1 

UP1:MOV AL,[SI]
MOV BL,[SI+1]
CMP AL,BL

; JNC DOWN  for descending
; JC DOWN for ascending

JC DOWN  
MOV DL,[SI+1]
XCHG [SI],DL
MOV [SI+1],DL

DOWN:INC SI
DEC CL
JNZ UP1
DEC CH
JNZ UP2

CODE ENDS
END START



