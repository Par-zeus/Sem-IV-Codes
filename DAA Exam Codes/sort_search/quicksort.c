#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *a,int low,int high){
    int pivot=a[low];
    int start=low,end=high;

    while(start<end){

        while(a[start]<=pivot && start<=high-1){
            start++;
        }
        while(a[end]>pivot && end>=low+1){
            end--;
        }

        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}

void quicksort(int arr[],int low,int high){

    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
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

    quicksort(arr, 0, n - 1);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}