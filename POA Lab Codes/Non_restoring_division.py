""" 
Name: Parth Das
SAP ID:60004220185
Div:C2-2
Roll No: C-111
AIM: To implement Non-Restoring Division Algorithm
"""

def shift_left(s):
    s = s[1:]
    s = s + "0"
    return s

def complement(s):
    d = {'0': '1', '1': '0'}
    e = ''.join(d[x] for x in s)
    l = len(e)
    sum = bin(int(e, 2) + int("1", 2))
    sum = sum[2:]
    return sum.zfill(l)

def add_zero_to_string(x):
    x = list(x)
    x[-1] = "0"
    return "".join(x)

def add_one_to_string(x):
    x = list(x)
    x[-1] = "1"
    return "".join(x)


q = int(input("Enter the dividend: "))
m = int(input("Enter the divisor: "))
Q = bin(q)[2:]  # final Q
M = bin(m)[2:]  # final M

if len(M) > len(Q):
    Q = Q.zfill(len(M))
else:
    M = M.zfill(len(Q))

print(f"Initial Values: A: {'0' * len(Q)}, Q: {Q}, M: {M}\n")

l = len(Q)
count = l

Mc = complement(M)

a = "0"
for i in range(l - 1):
    a = a + "0"

print("Steps of Division:")
while count > 0:
    s = a + Q

    value = shift_left(s)

    a = value[0:l]
    Q = value[l:]

    a = bin(int(a, 2) + int(Mc, 2))
    if len(a[2:]) == l + 1:
        a = a[3:]
    else:
        a = a[2:]

    if a[0] == "1":
        a = bin(int(a, 2) + int(M, 2))
        if len(a[2:]) == l + 1:
            a = a[3:]
        else:
            a = a[2:]

        Q = add_zero_to_string(Q)
        print(f"Step {l - count}: Left Shift and Subtract:  A: {a}")
        print(f"A: {a}  Q: {Q}  Unsuccessful")
    else:
        Q = add_one_to_string(Q)
        print(f"Step {l - count}: Left Shift and Add:  A: {a}")
        print(f"A: {a}  Q: {Q} Successful")

    count -= 1

    print(f"A: {a}  Q: {Q}  No Restoration\n")

print("\nFinal Results:")
# print("Remainder in Binary Form  :", a)
print("Remainder in Decimal Form :", int(a, 2))
# print("Quotient in Binary Form   :", Q)
print("Quotient in Decimal Form  :", int(Q, 2))


"""
Output 1:

Enter the dividend: 14
Enter the divisor: 3
Initial Values: A: 0000, Q: 1110, M: 0011

Steps of Division:
Step 0: Left Shift and Subtract:  A: 0001
A: 0001  Q: 1100  Unsuccessful
A: 0001  Q: 1100  No Restoration

Step 1: Left Shift and Add:  A: 0000
A: 0000  Q: 1001 Successful
A: 0000  Q: 1001  No Restoration

Step 2: Left Shift and Subtract:  A: 0001
A: 0001  Q: 0010  Unsuccessful
A: 0001  Q: 0010  No Restoration

Step 3: Left Shift and Subtract:  A: 0010
A: 0010  Q: 0100  Unsuccessful
A: 0010  Q: 0100  No Restoration


Final Results:
Remainder in Decimal Form : 2
Quotient in Decimal Form  : 4




Output 2:

Enter the dividend: 69
Enter the divisor: 9
Initial Values: A: 0000000, Q: 1000101, M: 0001001

Steps of Division:
Step 0: Left Shift and Subtract:  A: 0000001
A: 0000001  Q: 0001010  Unsuccessful
A: 0000001  Q: 0001010  No Restoration

Step 1: Left Shift and Subtract:  A: 0000010
A: 0000010  Q: 0010100  Unsuccessful
A: 0000010  Q: 0010100  No Restoration

Step 2: Left Shift and Subtract:  A: 0000100
A: 0000100  Q: 0101000  Unsuccessful
A: 0000100  Q: 0101000  No Restoration

Step 3: Left Shift and Subtract:  A: 0001000
A: 0001000  Q: 1010000  Unsuccessful
A: 0001000  Q: 1010000  No Restoration

Step 4: Left Shift and Add:  A: 0001000
A: 0001000  Q: 0100001 Successful
A: 0001000  Q: 0100001  No Restoration

Step 5: Left Shift and Add:  A: 0000111
A: 0000111  Q: 1000011 Successful
A: 0000111  Q: 1000011  No Restoration

Step 6: Left Shift and Add:  A: 0000110
A: 0000110  Q: 0000111 Successful
A: 0000110  Q: 0000111  No Restoration


Final Results:
Remainder in Decimal Form : 6
Quotient in Decimal Form  : 7

"""