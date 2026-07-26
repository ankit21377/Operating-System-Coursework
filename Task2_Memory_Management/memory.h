#ifndef MEMORY_H
#define MEMORY_H

#define MAX_FRAMES 3
#define MAX_PAGES 20

typedef struct
{
    int page;
    int frame;
    int valid;
} Page;

void initializeMemory(Page pageTable[]);
void displayPageTable(Page pageTable[]);

#endif