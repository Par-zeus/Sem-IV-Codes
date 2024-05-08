#include <stdio.h>  

void fifo(int incomingStream[], int pages, int frames) {
    int temp[frames],s,pageFaults = 0;
    printf("Incoming\t");
    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
        printf("Frame %d\t", i+1);
    }
    printf("\n");
    
    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s += 1;
            }
        }
        if (s == 0) 
        {
            pageFaults++;
            if (pageFaults <= frames) 
            {
                temp[pageFaults-1] = incomingStream[i];
            }
            else
            {
                temp[(pageFaults-1)%frames] = incomingStream[i];
            }
        }
        
        printf("%d\t",incomingStream[i]);
        for (int k = 0; k < frames; k++)
        {
            if (temp[k] == -1)
                printf("-\t");
            else
                printf("%d\t",temp[k]);
        }
        printf("\n");
    }
    printf("Total number of page faults: %d", pageFaults);
    printf("Total number of Hits: %d", (pages-pageFaults));
}


void lru(int incomingStream[], int pages, int frames) {
    int temp[frames], recent[frames];
    int s, pageFaults = 0, lru;

    printf("Incoming\t");
    for (int i = 0; i < frames; i++)
    {
        printf("Frame %d\t",(i+1));
    }
    printf("\n");
    

    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
        recent[i] = 0;
    }

    for (int i = 0; i < pages; i++)
    {
        s = 0;
        for (int j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s += 1;
                recent[j] = i+1;
                break;
            }
        }
        if (s==0)
        {
            pageFaults++;
            lru = 0;
            for (int n = 1; n < frames; n++)
            {
                if (recent[n] < recent[lru])
                {
                    lru = n;
                }
            }
            temp[lru] = incomingStream[i];
            recent[lru] = i+1;
        }
        
        printf("%d\t",incomingStream[i]);
        for (int k = 0; k < frames; k++)
        {
            if(temp[k] == -1)
                printf("-\t");
            else
                printf("%d\t", temp[k]);
        }
        printf("\n");
    }
    
    printf("Total number of page faults: %d\n", pageFaults);
    printf("Total number of Hits: %d", (pages - pageFaults));
}

void optimal(int incomingStream[], int pages, int frames)
{
    int temp[frames], nextUse[frames], pageFault = 0, dist = 0, k = 0, i, j;
    for (i = 0; i < frames; i++)
    {
        temp[i] = -1;
        nextUse[i] = 0;
    }
    printf("\nOPTIMAL:\n");
    for (i = 0; i < pages; i++)
    {
        int s = 0;
        for (j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                s = 1;
                break;
            }
        }
        if (s==0 && k < frames)
        {
            pageFault++;
            temp[k] = incomingStream[i];
            k++;
        }
        else if (s==0 && k == frames)
        {
            pageFault++;
            for (j = 0; j < frames; j++)
            {
                int current = temp[j];
                for (int c = i; c < pages; c++)
                {
                    if (current != incomingStream[c])
                        nextUse[j]++;
                    else
                        break;
                }
            }
            int max_count = 0, p;
            for (int m = 0; m < frames; m++)
            {
                if (nextUse[m] > max_count)
                {
                    max_count = nextUse[m];
                    p = m;
                }
            }
            temp[p] = incomingStream[i];
        }
        printf("\npage %d frame\t", incomingStream[i]);
        for (j = 0; j < frames; j++)
            printf("%d\t", temp[j]);
    }
    printf("\nNumber of Page Faults: %d\n", pageFault);
    printf("Number of Page Hits: %d\n", pages - pageFault);
    // printf("Hit Ratio: %f%%\n", (float)hit / (float)(pageFault + hit) * 100);
}

void main()  
{  
    int frames,pages;
    printf("Enter number of frames");
    scanf("%d",&frames);

    printf("Enter number of pages");
    scanf("%d",&pages);
    int incomingStream[pages];

    printf("Enter pages");
    for (int i = 0; i < pages; i++)
    {
        scanf("%d",&incomingStream[i]);
    }
    

    fifo(incomingStream, pages, frames);
    printf("\n");
    lru(incomingStream,pages,frames);
    printf("\n");
    optimal(incomingStream,pages,frames);

}