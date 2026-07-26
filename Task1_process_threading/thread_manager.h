#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include <pthread.h>

// Number of threads to create
#define NUM_THREADS 5

// Function to create and manage threads
void create_threads(void);

#endif