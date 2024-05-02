'''
Name: Parth Das
SAP ID: 60004220185
Roll No: C-111
Exp-4: To implement FIFO,LRU,Optimal Page Replacement Policy
'''

def fifo_algorithm(capacity, s):
    f, fault, top, pf = [], 0, 0, 'No'
    print("\nFIFO Algorithm\n")
    print("String|Frame →\t", end='')
    for i in range(capacity):
        print(i, end=' ')
    print("Fault\n   ↓\n")
    for i in s:
        if i not in f:
            if len(f) < capacity:
                f.append(i)
            else:
                f[top] = i
                top = (top + 1) % capacity
            fault += 1
            pf = 'Yes'
        else:
            pf = 'No'
        print("   %d\t\t" % i, end='')
        for x in f:
            print(x, end=' ')
        for x in range(capacity - len(f)):
            print(' ', end=' ')
        print(" %s" % pf)
    return fault

def lru_algorithm(capacity, s):
    f, st, fault, pf = [], [], 0, 'No'
    print("\nLRU Algorithm\n")
    print("String|Frame →\t", end='')
    for i in range(capacity):
        print(i, end=' ')
    print("Fault\n   ↓\n")
    for i in s:
        if i not in f:
            if len(f) < capacity:
                f.append(i)
                st.append(len(f) - 1)
            else:
                ind = st.pop(0)
                f[ind] = i
                st.append(ind)
            pf = 'Yes'
            fault += 1
        else:
            st.append(st.pop(st.index(f.index(i))))
            pf = 'No'
        print("   %d\t\t" % i, end='')
        for x in f:
            print(x, end=' ')
        for x in range(capacity - len(f)):
            print(' ', end=' ')
        print(" %s" % pf)
    return fault

def optimal_algorithm(capacity, s):
    f, fault, pf = [], 0, 'No'
    print("\nOptimal Algorithm\n")
    print("String|Frame →\t", end='')
    for i in range(capacity):
        print(i, end=' ')
    print("Fault\n   ↓\n")
    occurrence = [None for i in range(capacity)]
    for i in range(len(s)):
        if s[i] not in f:
            if len(f) < capacity:
                f.append(s[i])
            else:
                for x in range(len(f)):
                    if f[x] not in s[i + 1:]:
                        f[x] = s[i]
                        break
                    else:
                        occurrence[x] = s[i + 1:].index(f[x])
                else:
                    f[occurrence.index(max(occurrence))] = s[i]
            fault += 1
            pf = 'Yes'
        else:
            pf = 'No'
        print("   %d\t\t" % s[i], end='')
        for x in f:
            print(x, end=' ')
        for x in range(capacity - len(f)):
            print(' ', end=' ')
        print(" %s" % pf)
    return fault

capacity = int(input("Enter the number of frames: "))
s = list(map(int, input("Enter the reference string: ").strip().split()))

while True:
    ch = int(input("\n1. FIFO\n2. LRU\n3. Optimal\n-1. Exit\nEnter your choice:"))

    if ch == 1:
        fault = fifo_algorithm(capacity, s)
        print("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" % (len(s), fault, (fault / len(s)) * 100))

    elif ch == 2:
        fault = lru_algorithm(capacity, s)
        print("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" % (len(s), fault, (fault / len(s)) * 100))

    elif ch == 3:
        fault = optimal_algorithm(capacity, s)
        print("\nTotal Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" % (len(s), fault, (fault / len(s)) * 100))

    elif ch == -1:
        break

    else:
        print("Enter a valid choice")

'''
Output:

Enter the number of frames: 3
Enter the reference string: 2 3 2 1 5 2 4 5 3 2 5 2

1. FIFO
2. LRU
3. Optimal
-1. Exit
Enter your choice:1

FIFO Algorithm

String|Frame →  0 1 2 Fault
   ↓

   2            2      Yes
   3            2 3    Yes
   2            2 3    No
   1            2 3 1  Yes
   5            5 3 1  Yes
   2            5 2 1  Yes
   4            5 2 4  Yes
   5            5 2 4  No
   3            3 2 4  Yes
   2            3 2 4  No
   5            3 5 4  Yes
   2            3 5 2  Yes

Total Requests: 12
Total Page Faults: 9
Fault Rate: 75.00%

1. FIFO
2. LRU
3. Optimal
-1. Exit
Enter your choice:2

LRU Algorithm

String|Frame →  0 1 2 Fault
   ↓

   2            2      Yes
   3            2 3    Yes
   2            2 3    No
   1            2 3 1  Yes
   5            2 5 1  Yes
   2            2 5 1  No
   4            2 5 4  Yes
   5            2 5 4  No
   3            3 5 4  Yes
   2            3 5 2  Yes
   5            3 5 2  No
   2            3 5 2  No

Total Requests: 12
Total Page Faults: 7
Fault Rate: 58.33%

1. FIFO
2. LRU
3. Optimal
-1. Exit
Enter your choice:3

Optimal Algorithm

String|Frame →  0 1 2 Fault
   ↓

   2            2      Yes
   3            2 3    Yes
   2            2 3    No
   1            2 3 1  Yes
   5            2 3 5  Yes
   2            2 3 5  No
   4            4 3 5  Yes
   5            4 3 5  No
   3            4 3 5  No
   2            2 3 5  Yes
   5            2 3 5  No
   2            2 3 5  No

Total Requests: 12
Total Page Faults: 6
Fault Rate: 50.00%

1. FIFO
2. LRU
3. Optimal
-1. Exit
Enter your choice:-1
'''