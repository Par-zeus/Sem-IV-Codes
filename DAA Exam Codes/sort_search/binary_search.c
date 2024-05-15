#include<stdio.h>

void binary_search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array\n");
}

int main() {
    int n, key;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements of the array in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value to be found: ");
    scanf("%d", &key);

    binary_search(arr, n, key);
    return 0;
}
