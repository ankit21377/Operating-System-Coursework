#include <stdio.h>
#include "lru.h"

void lru(int pages[], int n)
{
    int frames[3] = {-1,-1,-1};
    int recent[3] = {0};
    int faults = 0;

    printf("\n========== LRU PAGE REPLACEMENT ==========\n");

    for(int i = 0; i < n; i++)
    {
        int hit = 0;

        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == pages[i])
            {
                hit = 1;
                recent[j] = i;
                break;
            }
        }

        if(!hit)
        {
            int pos = 0;

            for(int j = 1; j < 3; j++)
            {
                if(recent[j] < recent[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            recent[pos] = i;
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

    printf("\nLRU Page Faults = %d\n", faults);
}