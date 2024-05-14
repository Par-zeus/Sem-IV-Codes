#include <stdio.h>

struct obj {
    float p, w, x; // Profit, Weight, and Fraction of item to take
};

int main() {
    struct obj o[20], temp;
    int n, m, i, j;
    float capacity, profit = 0;
    
    printf("Enter the number of objects:\n");
    scanf("%d", &n);
    
    printf("Enter the size of the knapsack bag:\n");
    scanf("%d", &m);
    capacity = m;
    
    printf("Enter the profit and weight of each object:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the profit of object %d: ", i + 1);
        scanf("%f", &o[i].p);
        printf("Enter the weight of object %d: ", i + 1);
        scanf("%f", &o[i].w);
    }
    
    for (j = 0; j < n; j++) {
        o[j].x = 0; // Initialize fraction to 0
    }
    
    // Bubble sort items by profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (o[j].p / o[j].w < o[j + 1].p / o[j + 1].w) {
                temp = o[j];
                o[j] = o[j + 1];
                o[j + 1] = temp;
            }
        }
    }
    
    // Fill knapsack
    for (i = 0; i < n; i++) {
        if (capacity - o[i].w >= 0) {
            capacity -= o[i].w;
            profit += o[i].p;
            o[i].x = 1; // Take the whole item
        } else {
            break;
        }
    }
    
    // Take fraction of the last item if knapsack is not full
    if (capacity != 0) {
        o[i].x = capacity / o[i].w;
        profit += o[i].p * o[i].x;
        capacity = 0;
    }
    
    printf("The solution array is:\n");
    for (j = 0; j < n; j++) {
        printf("%0.2f\n", o[j].x);
    }
    
    printf("The total profit gained is %f\n", profit);
    
    return 0;
}
