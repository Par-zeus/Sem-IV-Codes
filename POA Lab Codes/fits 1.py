'''
Name: Parth Das
SAP ID: 60004220185
Roll No: C-111
Exp-3: To implement Best Fit/ First Fit /Worst fit Memory allocation Policy
'''

def implement_first_fit(block_size, process_sizes):
    allocation = [-1] * len(process_sizes)
    occupied = [0] * len(block_size)
    total_memory = sum(block_size)
    allocated_memory = 0

    for i in range(len(process_sizes)):
        for j in range(len(block_size)):
            if not occupied[j] and block_size[j] >= process_sizes[i]:
                allocation[i] = j
                occupied[j] = 1
                allocated_memory += process_sizes[i]
                break

    print("\nProcess No.\tProcess Size\tBlock no.")
    for i in range(len(process_sizes)):
        print(f"{i + 1}\t\t\t{process_sizes[i]}\t\t\t", end="")
        if allocation[i] != -1:
            print(allocation[i] + 1)
        else:
            print("Not Allocated")

    print(f"Percentage Utilization: {allocated_memory / total_memory * 100:.2f}%\n")


def best_fit(block_size, process_sizes):
    block_size_copy = block_size[:]
    allocation = [-1] * len(process_sizes)
    total_memory = sum(block_size)
    allocated_memory = 0

    for i in range(len(process_sizes)):
        best_idx = -1
        for j in range(len(block_size)):
            if block_size_copy[j] >= process_sizes[i]:
                if best_idx == -1 or block_size_copy[best_idx] > block_size_copy[j]:
                    best_idx = j

        if best_idx != -1:
            allocation[i] = best_idx
            block_size_copy[best_idx] -= process_sizes[i]
            allocated_memory += process_sizes[i]

    print("\nProcess No.\tProcess Size\tBlock no.")
    for i in range(len(process_sizes)):
        print(f"{i + 1}\t\t\t{process_sizes[i]}\t\t\t", end="")
        if allocation[i] != -1:
            print(allocation[i] + 1)
        else:
            print("Not Allocated")

    print(f"Percentage Utilization: {allocated_memory / total_memory * 100:.2f}%\n")


def implement_worst_fit(block_size, process_sizes):
    block_size_copy = block_size[:]
    allocation = [-1] * len(process_sizes)
    occupied = [0] * len(block_size)
    total_memory = sum(block_size)
    allocated_memory = 0

    for i in range(len(process_sizes)):
        index_placed = -1
        for j in range(len(block_size)):
            if block_size_copy[j] >= process_sizes[i] and not occupied[j]:
                if index_placed == -1 or block_size_copy[index_placed] < block_size_copy[j]:
                    index_placed = j
        if index_placed != -1:
            allocation[i] = index_placed
            occupied[index_placed] = 1
            block_size_copy[index_placed] -= process_sizes[i]
            allocated_memory += process_sizes[i]

    print("\nProcess No.\tProcess Size\tBlock no.")
    for i in range(len(process_sizes)):
        print(f"{i + 1}\t\t\t{process_sizes[i]}\t\t\t", end="")
        if allocation[i] != -1:
            print(allocation[i] + 1)
        else:
            print("Not Allocated")

    print(f"Percentage Utilization: {allocated_memory / total_memory * 100:.2f}%\n")


def main():

    block_size = [100, 500, 200, 300, 600]
    n = int(input("Enter the number of processes: "))
    process_sizes = []
    print(f"Enter the sizes of {n} processes:")
    for _ in range(n):
        process_sizes.append(int(input()))

    print("\n\nFIRST FIT \n\n")
    implement_first_fit(block_size, process_sizes)
    print("\n\nBEST FIT \n\n")
    best_fit(block_size, process_sizes)
    print("\n\nWORST FIT \n\n")
    implement_worst_fit(block_size, process_sizes)


if __name__ == "__main__":
    main()

'''
Output:

Enter the number of processes: 4
Enter the sizes of 4 processes:
100
100
200
200


FIRST FIT



Process No.     Process Size    Block no.
1                       100                     1
2                       100                     2
3                       200                     3
4                       200                     4
Percentage Utilization: 35.29%



BEST FIT



Process No.     Process Size    Block no.
1                       100                     1
2                       100                     3
3                       200                     4
4                       200                     2
Percentage Utilization: 35.29%



WORST FIT



Process No.     Process Size    Block no.
1                       100                     5
2                       100                     2
3                       200                     4
4                       200                     3
Percentage Utilization: 35.29%
'''