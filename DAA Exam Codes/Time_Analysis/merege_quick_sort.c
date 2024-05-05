#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void calculate(int n) {
    srand(time(NULL));
    clock_t start, end;

    int bestcase[n], avgcase[n], worstcase[n];
    for(int i = 0; i < n; i++) {
        bestcase[i] = i;
        avgcase[i] = rand() % n;
        worstcase[i] = n - i;
    }

    // Quick Sort Best Case
    start = clock();
    quicksort(bestcase, 0, n - 1);
    end = clock();
    printf("\nQuick-sort BestCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Quick Sort Average Case
    start = clock();
    quicksort(avgcase, 0, n - 1);
    end = clock();
    printf("\nQuick-sort AvgCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Quick Sort Worst Case
    start = clock();
    quicksort(worstcase, 0, n - 1);
    end = clock();
    printf("\nQuick-sort WorstCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Merge Sort Best Case
    start = clock();
    mergesort(bestcase, 0, n - 1);
    end = clock();
    printf("\nMerge-sort BestCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Merge Sort Average Case
    start = clock();
    mergesort(avgcase, 0, n - 1);
    end = clock();
    printf("\nMerge-sort AvgCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);

    // Merge Sort Worst Case
    start = clock();
    mergesort(worstcase, 0, n - 1);
    end = clock();
    printf("\nMerge-sort WorstCase: %f seconds", ((double)(end - start)) / CLOCKS_PER_SEC);
}

int main() {
    int n;
    printf("\nEnter the number of elements for which you want to do time analysis: ");
    scanf("%d", &n);
    calculate(n);
    return 0;
}
