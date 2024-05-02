print('''
 Name: Parth Das
 Roll No.: C-111
 SAP ID: 60004220185
 Div : C2-2
 ____________________________________________________________________________________________________________
 \t\t\t\tExperiment No. 1
 Aim: To implement Booth's Algorithm
''')

def conversion(a): 
    q=""
    current_n = len(a)
    temp = count- current_n
    if (current_n != count):
        q = "0"*temp + a
    return q

def add(x,y): 
    max_len = max(len(x),len(y))
    result = ''
    carry = 0
    for i in range(max_len-1, -1, -1):
           r = carry
           if x[i] == '1':
               r += 1
           if y[i] == '1':
               r += 1 
           if r % 2 == 1:
               result = "1" + result 
           else: 
               result = "0" + result
           if r<2:
               carry =0
           else:
               carry= 1  
    return result

def twoc(a):
    l = list(a)
    for i in range(len(l)):
         if l[i] == "1" :
             l[i] = "0"
         else: l[i] ="1"
    b = "0"*(len(l)-1) + "1" 
    return add("".join(l),b)

def right_shift(ac,q,q1): 
    a = ac[0]
    for i in range(1,len(ac)):
        a+=ac[i-1]
    b = ac[-1]
    for j in range(1,len(q)):
        b+=q[j-1]
    c = q[-1]
    return a,b,c

x = int(input("Enter the multiplicand:"))
y = int(input("Enter the multiplier:")) 
print("------------------------------------")
a = bin(x).replace("0b", "")#bin(8)=0b1000
b = bin(y).replace("0b", "")
negative_a=0
negative_b=0
if (a[0]=="-"):
        a = a.replace("-","")
        negative_a =1
if (b[0]=="-"):
        b = b.replace("-","")
        negative_b =1

if (len(a)>len(b)):
    count = len(a)+1
else:
    count = len(b) + 1

count1 = count
firstP = conversion(a) 
secondP = conversion(b) 
firstN = twoc(firstP) 
secondN = twoc(secondP) 

#BOOTH ALGO IMPLEMENTATION
if negative_a ==0:
    M = firstP  # M 2's Complement of multiplicand
    M2 = firstN # M2 2's Complement of multiplier
else:
    M = firstN
    M2 = firstP
if negative_b ==0:
    Q = secondP 
else:
    Q = secondN
AC = conversion("0")
Q1 = "0" 
print("The table for the Booth's algorithm is as follows:")
print("Count" +" "*count1 + "AC" +" "*count1 + "Q" +" "*count1 + "Q1" +" "*count1 + "Operation")
print(str(count) +" "*count1 + AC +" "*count1 + Q +" "*count1 + Q1 +" "*count1 + "initial")
print("\n")

while (count>0):
    compare = Q[-1] + Q1
    if compare[0]==compare[-1]:
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "right shift" 
    elif compare =="10":
        AC = add(AC,M2)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC-M and right shift"
    elif compare == "01":
        AC = add(AC,M)
        AC, Q, Q1 =right_shift(AC,Q,Q1)
        Op = "AC=AC+M and right shift"
    
    print(str(count-1) +" "*count1 + AC +" "*count1 + Q +" "*count1 + Q1 +" "*count1 + Op)
    print("\n")
    count = count-1
    answer = AC+Q

if negative_a==negative_b:
    ans_d = str(int(answer,2))
else:
    ans_d = "-" + str(int(twoc(answer),2))

print("The product in binary form is:" + answer)
print("Decimal conversion:" + ans_d)


'''
Output:


C:\Users\djsce.student\Documents\POA>python Booth'sAlgorithm.py

 Name: Parth Das
 Roll No.: C-111
 SAP ID: 60004220185
 Div : C2-2
 ____________________________________________________________________________________________________________
                                Experiment No. 1
 Aim: To implement Booth's Algorithm

Enter the multiplicand:4
Enter the multiplier:-7
------------------------------------
The table for the Booth's algorithm is as follows:
Count    AC    Q    Q1    Operation
4    0000    1001    0    initial


3    1110    0100    1    AC=AC-M and right shift


2    0001    0010    0    AC=AC+M and right shift


1    0000    1001    0    right shift


0    1110    0100    1    AC=AC-M and right shift


The product in binary form is:11100100
Decimal conversion:-28

C:\Users\djsce.student\Documents\POA>python Booth'sAlgorithm.py

 Name: Parth Das
 Roll No.: C-111
 SAP ID: 60004220185
 Div : C2-2
 ____________________________________________________________________________________________________________
                                Experiment No. 1
 Aim: To implement Booth's Algorithm

Enter the multiplicand:-2
Enter the multiplier:-3
------------------------------------
The table for the Booth's algorithm is as follows:
Count   AC   Q   Q1   Operation
3   000   101   0   initial


2   001   010   1   AC=AC-M and right shift


1   111   101   0   AC=AC+M and right shift


0   000   110   1   AC=AC-M and right shift


The product in binary form is:000110
Decimal conversion:6



C:\Users\djsce.student\Documents\POA>python Booth'sAlgorithm.py

 Name: Parth Das
 Roll No.: C-111
 SAP ID: 60004220185
 Div : C2-2
 ____________________________________________________________________________________________________________
                                Experiment No. 1
 Aim: To implement Booth's Algorithm

Enter the multiplicand:25
Enter the multiplier:-25
------------------------------------
The table for the Booth's algorithm is as follows:
Count      AC      Q      Q1      Operation
6      000000      100111      0      initial


5      110011      110011      1      AC=AC-M and right shift


4      111001      111001      1      right shift


3      111100      111100      1      right shift


2      001010      111110      0      AC=AC+M and right shift


1      000101      011111      0      right shift


0      110110      001111      1      AC=AC-M and right shift


The product in binary form is:110110001111
Decimal conversion:-625


'''