#include <stdio.h>
#include "memory.h"

void initializeMemory(Page pageTable[])
{
    for(int i = 0; i < MAX_PAGES; i++)
    {
        pageTable[i].page = i;
        pageTable[i].frame = -1;
        pageTable[i].valid = 0;
    }
}

void displayPageTable(Page pageTable[])
{
    printf("\n========== PAGE TABLE ==========\n");
    printf("Page\tFrame\tValid\n");

    for(int i = 0; i < MAX_PAGES; i++)
    {
        printf("%d\t%d\t%d\n",
               pageTable[i].page,
               pageTable[i].frame,
               pageTable[i].valid);
    }
}