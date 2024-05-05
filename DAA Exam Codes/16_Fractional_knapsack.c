#include <stdio.h>
#include <stdlib.h>

struct Items
{
    float weight;
    float profit;
    float ratio;
};
int compare(const void *a, const void *b)
{
    struct Items *ratioA = (struct Items *)a;
    struct Items *ratioB = (struct Items *)b;

    double diff = ratioB->ratio - ratioA->ratio;

    if (diff > 0)
        return 1;
    else if (diff < 0)
        return -1;
    else
        return 0;
}
float knapsack(struct Items item[], int kw, int n)
{
    float t_profit = 0.0;
    for (int i = 0; i < n; i++)
    {

        if (kw == 0)
            break;
        else if (item[i].weight <= kw)
        {
            kw -= item[i].weight;
            t_profit += item[i].profit;
        }
        else
        {
            t_profit +=( item[i].profit * kw / item[i].weight);
        }
    }
    return t_profit;
}
int main()
{
    int kw, n;
    struct Items item[10];
    printf("\nEnter the knapsack weight: ");
    scanf("%d", &kw);
    printf("\nEnter the number of elements in knapsack: ");
    scanf("%d", &n);

    printf("\nEnter Details for each element.");
    for (int i = 0; i < n; i++)
    {
        printf("\nDetails for %d", i + 1);
        printf("\nEnter profit and weight: ");
        scanf("%f %f", &item[i].profit, &item[i].weight);
        item[i].ratio = item[i].profit / item[i].weight;
    }

    qsort(item, n, sizeof(struct Items), compare);

    float max_profit = knapsack(item, kw, n);
    printf("\nMaximum profit gained: %.2f", max_profit);
    return 0;
}