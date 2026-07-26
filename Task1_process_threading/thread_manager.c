#include <stdio.h>
#include <pthread.h>
#include "thread_manager.h"

// Shared counter
int shared_counter = 0;

// Mutex
pthread_mutex_t counter_mutex;

// Function executed by each thread
void *thread_task(void *arg)
{
    int thread_id = *(int *)arg;

    printf("Thread %d started.\n", thread_id);

    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&counter_mutex);

        shared_counter++;

        pthread_mutex_unlock(&counter_mutex);
    }

    printf("Thread %d finished.\n", thread_id);

    pthread_exit(NULL);
}


// Create and manage threads
void create_threads(void)
{
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize mutex
    pthread_mutex_init(&counter_mutex, NULL);


    // Create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i + 1;

        pthread_create(
            &threads[i],
            NULL,
            thread_task,
            &thread_ids[i]
        );
    }


    // Wait for all threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }


    // Destroy mutex
    pthread_mutex_destroy(&counter_mutex);


    printf("\nFinal Counter Value: %d\n", shared_counter);
}