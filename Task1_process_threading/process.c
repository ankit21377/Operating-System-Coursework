#include <stdio.h>
#include "process.h"

// Initialize process information
void initialize_processes(Process processes[], int count)
{
    for (int i = 0; i < count; i++)
    {
        processes[i].pid = i + 1;
        processes[i].burst_time = (i + 1) * 2;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }
}

// Display all processes
void display_processes(Process processes[], int count)
{
    printf("\n---------------------------------------------\n");
    printf("PID\tBurst Time\tRemaining Time\tStatus\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d\t%d\t\t%d\t\t",
               processes[i].pid,
               processes[i].burst_time,
               processes[i].remaining_time);

        if (processes[i].completed)
        {
            printf("Completed\n");
        }
        else
        {
            printf("Waiting\n");
        }
    }

    printf("---------------------------------------------\n");
}