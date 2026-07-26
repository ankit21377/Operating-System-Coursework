#include <stdio.h>
#include <pthread.h>
#include "deadlock.h"

pthread_mutex_t resource1;
pthread_mutex_t resource2;

void deadlock_prevention_demo(void)
{
    pthread_mutex_init(&resource1, NULL);
    pthread_mutex_init(&resource2, NULL);

    printf("\n===============================\n");
    printf("Deadlock Prevention Demo\n");
    printf("===============================\n");

    printf("Locking Resource 1...\n");
    pthread_mutex_lock(&resource1);

    printf("Locking Resource 2...\n");
    pthread_mutex_lock(&resource2);

    printf("Resources acquired successfully.\n");

    pthread_mutex_unlock(&resource2);
    pthread_mutex_unlock(&resource1);

    printf("Resources released successfully.\n");

    pthread_mutex_destroy(&resource1);
    pthread_mutex_destroy(&resource2);
}