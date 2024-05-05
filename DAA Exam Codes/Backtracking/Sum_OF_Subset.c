#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to find all subsets with given sum
void findSubsets(int set[], bool selected[], int n, int targetSum, int subsetSum, int index)
{
    if (subsetSum == targetSum)
    {
        // Print the subset
        printf("{ ");
        bool isFirst = true;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                if (!isFirst)
                {
                    printf(" ");
                }
                printf("%d", set[i]);
                isFirst = false;
            }
        }
        printf(" }\n");
        return;
    }

    if (index == n || subsetSum > targetSum)
        return;

    // Include the current element and move to the next one
    selected[index] = true;
    findSubsets(set, selected, n, targetSum, subsetSum + set[index], index + 1);

    // Exclude the current element and move to the next one
    selected[index] = false;
    findSubsets(set, selected, n, targetSum, subsetSum, index + 1);
}

int main()
{
    int set[MAX_SIZE];
    bool selected[MAX_SIZE] = {false};
    int n, targetSum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum %d are:\n", targetSum);
    findSubsets(set, selected, n, targetSum, 0, 0);
    return 0;
}
