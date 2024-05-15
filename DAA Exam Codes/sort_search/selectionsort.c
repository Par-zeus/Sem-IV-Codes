#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int *a,int n){

    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }

        swap(&a[min],&a[i]);
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
    
    selectionsort(arr, n);
    return 0;
}