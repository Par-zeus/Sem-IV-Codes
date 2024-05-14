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

    // Include the current element in the subset
    subset[currentIndex] = set[start];
    subsetSumUtil(currentIndex + 1, currentSum + set[start], start + 1);
    
    // Exclude the current element from the subset
    subsetSumUtil(currentIndex, currentSum, start + 1);
}
int main()
{

    printf("Enter the size of the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    subsetSumUtil(0, 0, 0);
    return 0;
}
