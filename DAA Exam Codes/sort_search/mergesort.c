#include <stdio.h>

void merger(int a[], int low, int mid, int high)
{
    int i = low, k = low, j = mid + 1;
    int b[100];

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    for (int m = low; m <= high; m++)
    {
        a[m] = b[m];
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merger(arr, low, mid, high);
    }
}

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}