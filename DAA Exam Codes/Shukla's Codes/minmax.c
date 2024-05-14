#include<stdio.h>
void minmax(int lb, int ub, int *max, int *min); // Change 1: Use pointers to pass max and min

int a[100];

int main() // Change 2: Use int main() instead of void main()
{
    int n, i, max, min; // Change 3: Declare max and min in main
    printf("Enter the number of elements in an array:\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the %d element:\n", i + 1);
        scanf("%d", &a[i]);
    }
    minmax(0, n - 1, &max, &min); // Change 4: Pass addresses of max and min
    printf("The largest element in the given array is %d\n", max);
    printf("The smallest element in the given array is %d\n", min);
    return 0; // Change 5: Return 0 at the end of main
}

void minmax(int lb, int ub, int *max, int *min) // Change 6: Use pointers to modify max and min
{
    int mid, max1, min1;
    if(lb == ub)
    {
        *max = *min = a[lb]; // Change 7: Use *max and *min to assign values
    }
    else if(ub == lb + 1)
    {
        if(a[lb] > a[ub])
        {
            *max = a[lb];
            *min = a[ub];
        }
        else
        {
            *max = a[ub];
            *min = a[lb];
        }
    }
    else
    {
        mid = (lb + ub) / 2;
        minmax(lb, mid, max, min);
        minmax(mid + 1, ub, &max1, &min1); // Change 8: Pass addresses of max1 and min1
        if(max1 > *max)
        {
            *max = max1;
        }
        if(min1 < *min)
        {
            *min = min1;
        }
    }
}
