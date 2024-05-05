#include <stdio.h>
#include <stdlib.h>

struct MinMax
{
    int min;
    int max;
};

struct MinMax min_max(int arr[], int low, int high)
{
    struct MinMax result, left, right;
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if (high == low - 1)
    {
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        return result;
    }

    int mid = low + (high - low) / 2;
    left = min_max(arr, 0, mid);
    right = min_max(arr, mid + 1, high);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    return result;
}

int main()
{
    int n;
    printf("\nEnter The size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct MinMax result = min_max(arr, 0, n - 1);
    printf("\nMinimum value: %d", result.min);
    printf("\nMaximum value: %d", result.max);
    return 0;
}