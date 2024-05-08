#include <stdio.h>
#include<conio.h>
void implementFirstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocate[processes];
    int occupied[blocks];
    int totalMemory = 0;
    int allocatedMemory = 0;

    for (int i = 0; i < processes; i++) {
        allocate[i] = -1;
    }

    for (int i = 0; i < blocks; i++) {
        occupied[i] = 0;
        totalMemory += blockSize[i];
    }

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (!occupied[j] && blockSize[j] >= processSize[i]) {
                allocate[i] = j;
                occupied[j] = 1;
                allocatedMemory += processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++) {
        printf("%d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n", allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("Percentage Utilization: %.2f%%\n", ((float)allocatedMemory / totalMemory) * 100);
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int blockSizeCopy[m];
    int allocation[n];
    int totalMemory = 0;
    int allocatedMemory = 0;

    for (int i = 0; i < m; i++)
        blockSizeCopy[i] = blockSize[i];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
        totalMemory += blockSize[i];

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizeCopy[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSizeCopy[bestIdx] > blockSizeCopy[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSizeCopy[bestIdx] -= processSize[i];
            allocatedMemory += processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("Percentage Utilization: %.2f%%\n", ((float)allocatedMemory / totalMemory) * 100);
}

void implementWorstFit(int blockSize[], int m, int processSize[], int n) {
    int blockSizeCopy[m];
    int allocation[n];
    int occupied[m];
    int totalMemory = 0;
    int allocatedMemory = 0;

    for (int i = 0; i < m; i++)
        blockSizeCopy[i] = blockSize[i];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++)
        occupied[i] = 0;

    for (int i = 0; i < m; i++)
        totalMemory += blockSize[i];

    for (int i = 0; i < n; i++) {
        int indexPlaced = -1;
        for (int j = 0; j < m; j++) {
            if (blockSizeCopy[j] >= processSize[i] && !occupied[j]) {
                if (indexPlaced == -1 || blockSizeCopy[indexPlaced] < blockSizeCopy[j]) {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1) {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSizeCopy[indexPlaced] -= processSize[i];
            allocatedMemory += processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("Percentage Utilization: %.2f%%\n", ((float)allocatedMemory / totalMemory) * 100);
}

void nextFit(int blockSize[], int m, int processSize[], int n) {
    // Stores block id of the block allocated to a process
    // Initially no block is assigned to any process
    int allocation[n];
    int totalMemory = 0;
    int allocatedMemory = 0;
    int j = 0;
    int t = m - 1;
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < m; i++)
        totalMemory += blockSize[i];
    // Pick each process and find suitable blocks according to its size and assign to it
    for (int i = 0; i < n; i++) {
        // Do not start from the beginning
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                allocatedMemory+=processSize[i];
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                // Set a new end point
                t = (j - 1) % m;
                break;
            }
            if (t == j) {
                // Set a new end point
                t = (j - 1) % m;
                // Break the loop after going through all memory blocks
                break;
            }
            // Mod m will help in traversing the blocks from starting block after we reach the end
            j = (j + 1) % m;
        }
    }

    printf("Process No.\t Process Size\t Block no.\n");

    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
    printf("Percentage Utilization: %.2f%%\n", ((float)allocatedMemory / totalMemory) * 100);
}

int main() {
    int blockSize[] = {100,200,400,600,500};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
   
    int n,ch;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
   
    int processSize[n];
    printf("Enter the sizes of %d processes:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    while(ch!=5)
    {
        printf("\nMain Menu\n");
        printf("1.First Fit\n");
        printf("2.Best Fit\n");
        printf("3.Worst Fit\n");
        printf("4.Next Fit\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            implementFirstFit(blockSize, m, processSize, n);
            break;
            case 2:
            bestFit(blockSize,m,processSize,n);
            break;
            case 3:
            implementFirstFit(blockSize, m, processSize, n);
            break;
            case 4:
            nextFit(blockSize,m,processSize,n);
            break;
            case 5:
            printf("Thank you");
            break;
            default:
            printf("Invalid");
        }
    }
    getch();
}