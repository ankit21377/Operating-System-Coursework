#include <stdio.h>
#include <time.h>
#include "audit.h"

void logActivity(const char activity[])
{
    FILE *fp = fopen("audit_log.txt","a");

    if(fp == NULL)
    {
        printf("Unable to Create Audit Log.\n");
        return;
    }

    time_t currentTime = time(NULL);

    fprintf(fp,"%s : %s", ctime(&currentTime), activity);
    fprintf(fp,"\n");

    fclose(fp);
}