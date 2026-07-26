#include <stdio.h>

#include "process.h"
#include "thread_manager.h"
#include "synchronization.h"
#include "scheduler.h"
#include "deadlock.h"

int main()
{
    Process processes[MAX_PROCESSES];

    printf("=====================================\n");
    printf("Task 1: Process Management and Threading\n");
    printf("=====================================\n");

    initialize_processes(processes, 4);

    display_processes(processes, 4);

    printf("\nCreating Threads...\n");
    create_threads();

    printf("\nSynchronization Demo\n");
    synchronization_demo();

    printf("\nRace Condition Demo\n");
    race_condition_demo();

    round_robin(processes, 4);

    deadlock_prevention_demo();

    printf("\nProgram Finished Successfully.\n");

    return 0;
}