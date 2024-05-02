""" 
Name: Parth Das
SAP ID:60004220185
Div:C2-2
Roll No: C-111
 AIM: To implement Restoring Division Algorithm
"""

def deci_to_bin(n):
    return bin(n).replace("0b", "")

def shift_left(C, AC, Q):
    # Update C with the MSB of AC
    C = AC[0]
    
    # Shift AC to the left by one position
    temp_AC = list(AC)
    for i in range(1, len(AC)):
        temp_AC[i-1] = temp_AC[i]
    temp_AC[len(AC)-1] = Q[0]
    AC = ''.join(temp_AC)

    # Shift Q to the left by one position
    temp_Q = list(Q)
    for i in range(1, len(Q)):
        temp_Q[i-1] = temp_Q[i]
    temp_Q[len(Q)-1] = '_'
    Q = ''.join(temp_Q)
    
    return C, AC, Q

def operation(C, AC, M):
    # Perform addition of C and AC with M
    temp = bin(int(C + AC, 2) + int(M, 2))
    temp = temp.replace("0b", "")

    # Discard the carry while operation is done
    if len(temp) > len(M):
        temp = temp[1:]
    return temp[0], temp[1:]

# Main function
AC = ''
C = '0'

Q = input("Enter the dividend(Q)  :  ")
Q = deci_to_bin(int(Q))

M = input("Enter the divisor(M)   :  ")
M = deci_to_bin(int(M))

# Initialize AC with zeros based on the length of Q or M
if len(Q) > len(M):
    AC = '0' * len(Q)
else:
    AC = '0' * len(M)

print("Initial C value is     : ", C)
print("Initial AC value is    : ", AC)
print("Initial Q value is     : ", Q)

# Make sure M has the same length as Q by adding leading zeros
for i in range(len(Q) - len(M)):
    M = '0' + M
# Add one bit extra to M
M = '0' + M

print("Value of M is          : ", M)

# Calculate the two's complement of M
M_array = list(M)
for i in range(len(M)):
    if M[i] == '0':
        M_array[i] = '1'
    if M[i] == '1':
        M_array[i] = '0'
M_negative = ''.join(M_array)
M_negative = bin(int(M_negative, 2) + int('1', 2))
M_negative = M_negative.replace("0b", "")
print("Two's complement of M  : ", M_negative)
print()

print("---------------------------------------------------------------------------------------------------------------------")
print("\t C ", " "*int(len(AC)/2), "AC", " "*int(len(AC)/2), " "*int(len(Q)/2), "Q", " "*int(len(Q)/2), "     Operation done")
print("---------------------------------------------------------------------------------------------------------------------")
print("\t", C, "  ", AC, "  ", Q, "   ", "Initial values")
print()

for i in range(len(Q)):
    print("step", (i+1), ":  ")
    C, AC, Q = shift_left(C, AC, Q)

    print("\t", C, "  ", AC, "  ", Q, "   ", " Shift left ")

    C, AC = operation(C, AC, M_negative)
    print("\t", C, "  ", AC, "  ", Q, "   ", "AC=AC-M ")
   
    if C == '1':
        temp_Q = list(Q)
        temp_Q[len(Q)-1] = '0'
        Q = ''.join(temp_Q)
       
        C, AC = operation(C, AC, M)
        print("\t", C, "  ", AC, "  ", Q, "   ", "AC=AC-M")
       
    else:
        temp_Q = list(Q)
        temp_Q[len(Q)-1] = '1'
        Q = ''.join(temp_Q)
    print()
   
print('\nFinal values')    
print("\t", C, "  ", AC, "  ", Q)
print()
print("Remainder=(C,AC)       : ", int(C+AC, 2))
print("Quotient=(Q)           : ", int(Q, 2))

"""
Output 1:

Enter the dividend(Q)  :  25
Enter the divisor(M)   :  25
Initial C value is     :  0
Initial AC value is    :  00000
Initial Q value is     :  11001
Value of M is          :  011001
Two's complement of M  :  100111

---------------------------------------------------------------------------------------------------------------------
         C     AC       Q         Operation done
---------------------------------------------------------------------------------------------------------------------
         0    00000    11001     Initial values

step 1 :
         0    00001    1001_      Shift left
         1    01000    1001_     AC=AC-M
         0    00001    10010     AC=AC-M

step 2 :
         0    00011    0010_      Shift left
         1    01010    0010_     AC=AC-M
         0    00011    00100     AC=AC-M

step 3 :
         0    00110    0100_      Shift left
         1    01101    0100_     AC=AC-M
         0    00110    01000     AC=AC-M

step 4 :
         0    01100    1000_      Shift left
         1    10011    1000_     AC=AC-M
         0    01100    10000     AC=AC-M

step 5 :
         0    11001    0000_      Shift left
         0    00000    0000_     AC=AC-M


Final values
         0    00000    00001

Remainder=(C,AC)       :  0
Quotient=(Q)           :  1


Output 2:

Enter the dividend(Q)  :  69
Enter the divisor(M)   :  5
Initial C value is     :  0
Initial AC value is    :  0000000
Initial Q value is     :  1000101
Value of M is          :  00000101
Two's complement of M  :  11111011

---------------------------------------------------------------------------------------------------------------------
         C      AC         Q          Operation done
---------------------------------------------------------------------------------------------------------------------
         0    0000000    1000101     Initial values

step 1 :
         0    0000001    000101_      Shift left
         1    1111100    000101_     AC=AC-M
         0    0000001    0001010     AC=AC-M

step 2 :
         0    0000010    001010_      Shift left
         1    1111101    001010_     AC=AC-M 
         0    0000010    0010100     AC=AC-M

step 3 :
         0    0000100    010100_      Shift left
         1    1111111    010100_     AC=AC-M
         0    0000100    0101000     AC=AC-M

step 4 :
         0    0001000    101000_      Shift left
         0    0000011    101000_     AC=AC-M

step 5 :
         0    0000111    010001_      Shift left
         0    0000010    010001_     AC=AC-M

step 6 :
         0    0000100    100011_      Shift left
         1    1111111    100011_     AC=AC-M
         0    0000100    1000110     AC=AC-M

step 7 :
         0    0001001    000110_      Shift left
         0    0000100    000110_     AC=AC-M


Final values
         0    0000100    0001101

Remainder=(C,AC)       :  4
Quotient=(Q)           :  13
"""