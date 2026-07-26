#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

#define TIME_QUANTUM 2

void round_robin(Process processes[], int count);

#endif