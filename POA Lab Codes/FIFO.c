#include <stdio.h>

int main()  
{  
    int incomingStream[15];
    int pageFaults = 0;  
    int frames = 3;  
    int m, n, s, pages;  

    printf("Enter no. of pages: ");
    scanf("%d", &pages);
    printf("Enter the pages: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &incomingStream[i]);
    }

    printf(" Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3 ");  
    int temp[frames];  
    for (m = 0; m < frames; m++) {  
        temp[m] = -1;  
    }  

    int currentFrame = 0; // Initialize current frame index

    for (m = 0; m < pages; m++) {  
        s = 0;  
        for (n = 0; n < frames; n++) {  
            if (incomingStream[m] == temp[n]) {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  

        if ((pageFaults <= frames) && (s == 0)) {  
            temp[currentFrame] = incomingStream[m];  
            currentFrame = (currentFrame + 1) % frames; // Move to the next frame
        }  
        else if (s == 0) {  
            temp[currentFrame] = incomingStream[m];  
            currentFrame = (currentFrame + 1) % frames; // Move to the next frame
        }  

        printf("\n");  
        printf("%d\t\t\t", incomingStream[m]);  
        for (n = 0; n < frames; n++) {  
            if (temp[n] != -1)  
                printf(" %d\t\t\t", temp[n]);  
            else  
                printf(" - \t\t\t");  
        }  
    }  

    printf("\nTotal Page Faults:\t%d\n", pageFaults);  

    return 0;  
}