#include <stdio.h>
#include <stdlib.h>

struct Tasks
{
    int start;
    int finish;
};
int compare(const void *a, const void *b)
{
    struct Tasks *taskA = (struct Tasks *)a;
    struct Tasks *taskB = (struct Tasks *)b;

    return (taskA->finish - taskB->finish);
}

int non_conflict_tasks(int n, struct Tasks tasks[])
{
    qsort(tasks, n, sizeof(struct Tasks), compare);
    int count = 1; // First Task is always Selected
    int j = 0;     // last selected task
    int i = 1;     // Next task selected after 1st task

    printf("A%d ->", j);
    while (i < n)
    {
        // compare if current start time is greater than previous finish time
        // i.e act 2= starttime=6
        // act 1 = finishtime=5 then success
        if (tasks[i].start >= tasks[j].finish)
        {
            printf("A%d ->", i);
            j = i; // changing the previous finish task index
            count++;
        }
            i++;
    }
    printf("END");
    return count;
}
int main()
{
    int n;
    printf("\nEnter the number of activities: ");
    scanf("%d", &n);
    struct Tasks tasks[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nActivity %d", i + 1);
        printf("\nEnter Start and Finish Time: ");
        scanf("%d %d", &tasks[i].start, &tasks[i].finish);
    }
    int tasks_count = non_conflict_tasks(n, tasks);
    printf("\n The maximum number of non-conflictitng tasks: %d", tasks_count);
    return 0;
}