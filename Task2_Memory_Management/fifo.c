#include <stdio.h>
#include "fifo.h"

void fifo(int pages[], int n)
{
    int frames[3] = {-1, -1, -1};
    int pointer = 0;
    int faults = 0;

    printf("\n========== FIFO PAGE REPLACEMENT ==========\n");

    for(int i = 0; i < n; i++)
    {
        int hit = 0;

        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == pages[i])
            {
                hit = 1;
                break;
            }
        }

        if(!hit)
        {
            frames[pointer] = pages[i];
            pointer = (pointer + 1) % 3;
            faults++;
        }

        printf("Page %d -> ", pages[i]);

        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\n");
    }

    printf("\nFIFO Page Faults = %d\n", faults);
}