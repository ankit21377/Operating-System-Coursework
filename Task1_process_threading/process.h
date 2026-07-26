#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 10

typedef struct
{
    int pid;
    int burst_time;
    int remaining_time;
    int completed;
} Process;

void initialize_processes(Process processes[], int count);
void display_processes(Process processes[], int count);

#endif