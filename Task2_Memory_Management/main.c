#include <stdio.h>
#include "memory.h"
#include "fifo.h"
#include "lru.h"

int main()
{
    Page pageTable[MAX_PAGES];

    int pages[] = {
        7, 0, 1, 2, 0,
        3, 0, 4, 2, 3,
        0, 3, 2
    };

    int totalPages = sizeof(pages) / sizeof(pages[0]);

    printf("=========================================\n");
    printf(" Task 2 : Memory Management Simulation\n");
    printf("=========================================\n");

    initializeMemory(pageTable);

    displayPageTable(pageTable);

    fifo(pages, totalPages);

    lru(pages, totalPages);

    printf("\n=========================================\n");
    printf(" Program Finished Successfully\n");
    printf("=========================================\n");

    return 0;
}