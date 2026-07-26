#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <pthread.h>

// Shared resource
extern int shared_resource;

// Mutex for synchronization
extern pthread_mutex_t resource_mutex;

// Demonstrate synchronization using mutex
void synchronization_demo(void);

// Demonstrate race condition without mutex
void race_condition_demo(void);

// Create and manage threads
void create_threads(void);

#endif