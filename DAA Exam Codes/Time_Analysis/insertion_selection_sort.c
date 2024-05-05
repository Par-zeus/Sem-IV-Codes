#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selection_sort(int arr[], int n)
{
    int min, i, j;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {

            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
void calculate(int n)
{
    srand(time(NULL));
    int bestcase[n], avgcase[n], worstcase[n];

    for (int i = 0; i < n; i++)
    {
        bestcase[i] = i;
        avgcase[i] = rand() % 10;
        worstcase[i] = n - i;
    }

    clock_t start, end;

    // Insertion Sort - Best Case
    start=clock();
    insertion_sort(bestcase,n);
    end=clock();
    printf("\nInsertion Sort - Best Case :%f seconds\n",( (double)(end-start) )/CLOCKS_PER_SEC);

    // Insertion Sort - Avg Case
    start=clock();
    insertion_sort(avgcase,n);
    end=clock();
    printf("\nInsertion Sort - Average Case :%f seconds\n",( (double)(end-start) )/CLOCKS_PER_SEC);

    // Insertion Sort - Worst Case
    start=clock();
    insertion_sort(worstcase,n);
    end=clock();
    printf("\nInsertion Sort -Worst Case :%f seconds\n",( (double)(end-start) )/CLOCKS_PER_SEC);

    // Selection Sort - Best Case
    start = clock();
    selection_sort(bestcase, n);
    end = clock();
    printf("\nSelection Sort - Best Case :%f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Selection Sort - Avg Case
    start = clock();
    selection_sort(avgcase, n);
    end = clock();
    printf("\nSelection Sort - Average Case :%f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Selection Sort - Worst Case
    start = clock();
    selection_sort(worstcase, n);
    end = clock();
    printf("\nSelection Sort - Worst Case :%f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
int main()
{
    int n;
    printf("\nEnter the number of elements for which u want to do time analysis: ");
    scanf("%d", &n);
    calculate(n);

    return 0;
}