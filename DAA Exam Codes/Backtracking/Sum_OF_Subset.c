#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
int set[MAX_SIZE];
int subset[MAX_SIZE];
int n;
int targetSum;

void subsetSumUtil(int currentIndex, int currentSum, int start)
{
    if (currentSum == targetSum)
    {
       
        printf("Subset with sum %d found: ", targetSum);
        for (int i = 0; i < currentIndex; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
    }
    if (currentSum >= targetSum || start == n)
    {
        return;
    }

    
    
    subset[currentIndex] = set[start];
    subsetSumUtil(currentIndex + 1, currentSum + set[start], start + 1);
    
    
    subsetSumUtil(currentIndex, currentSum, start + 1);
}

void subsetSum(int inputSet[], int setSize, int sum)
{
    n = setSize;
    targetSum = sum;
    for (int i = 0; i < n; i++)
    {
        set[i] = inputSet[i];
    }
    subsetSumUtil(0, 0, 0);
}
int main()
{
    int setSize, sum;
    printf("Enter the size of the set: ");
    scanf("%d", &setSize);
    printf("Enter the elements of the set: \n");
    for (int i = 0; i < setSize; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    subsetSum(set, setSize, sum);
    return 0;
}
