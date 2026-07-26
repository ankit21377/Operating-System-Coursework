#include <stdio.h>
#include <pthread.h>
#include "synchronization.h"

int shared_resource = 0;
pthread_mutex_t resource_mutex;

// Increment shared resource using mutex
void synchronization_demo(void)
{
    pthread_mutex_init(&resource_mutex, NULL);

    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&resource_mutex);

        shared_resource++;

        pthread_mutex_unlock(&resource_mutex);
    }

    printf("Shared Resource (With Mutex): %d\n", shared_resource);

    pthread_mutex_destroy(&resource_mutex);
}

// Increment shared resource without mutex
void race_condition_demo(void)
{
    shared_resource = 0;

    for (int i = 0; i < 100000; i++)
    {
        shared_resource++;
    }

    printf("Shared Resource (Without Mutex): %d\n", shared_resource);
}