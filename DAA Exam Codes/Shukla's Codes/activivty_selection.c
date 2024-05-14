#include <stdio.h>

struct activity{
  int end;
  int job_id;
  int start;
};
struct activity a[10];
void main() {
    int n,i,j;
    struct activity temp;
    printf("Enter the number of jobs\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the id of job %d\n",i+1);
        scanf("%d",&a[i].job_id);
        printf("Enter the start time of job %d\n",i+1);
        scanf("%d",&a[i].start);
        printf("Enter the end time of job %d\n",i+1);
        scanf("%d",&a[i].end);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j].end>a[j].end)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The job sequence is:\n");
    int check=a[0].end;
    printf("J%d\n",a[0].job_id);
    for(i=0;i<n;i++)
    {
        if(a[i+1].start>=check)
        {
            printf("J%d\n",a[i+1].job_id);
            check=a[i+1].end;
        }
    }
}