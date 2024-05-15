#include<stdio.h>
void insertionsort(int a[],int n){
    int key,j;
    for(int i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }

    printf("\nSorted Array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
      int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements of the array in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    insertionsort(arr, n);
    return 0;
}