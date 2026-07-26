#include <stdio.h>
#include "scheduler.h"

void round_robin(Process processes[], int count)
{
    int completed = 0;

    printf("\n===============================\n");
    printf("Round Robin Scheduling\n");
    printf("===============================\n");

    while (completed < count)
    {
        for (int i = 0; i < count; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                printf("Running Process P%d\n", processes[i].pid);

                if (processes[i].remaining_time > TIME_QUANTUM)
                {
                    processes[i].remaining_time -= TIME_QUANTUM;
                }
                else
                {
                    processes[i].remaining_time = 0;
                    processes[i].completed = 1;
                    completed++;

                    printf("Process P%d Completed\n", processes[i].pid);
                }
            }
        }
    }

    printf("All Processes Completed.\n");
}