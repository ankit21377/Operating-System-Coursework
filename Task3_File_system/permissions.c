#include <stdio.h>
#include "permissions.h"

static int readPermission = 1;
static int writePermission = 1;
static int executePermission = 0;

void displayPermissions()
{
    printf("\n========== FILE PERMISSIONS ==========\n");

    printf("Read    : %s\n", readPermission ? "Allowed" : "Denied");
    printf("Write   : %s\n", writePermission ? "Allowed" : "Denied");
    printf("Execute : %s\n", executePermission ? "Allowed" : "Denied");
}

void changePermissions()
{
    printf("\nChange File Permissions\n");

    printf("Allow Read (1/0): ");
    scanf("%d",&readPermission);

    printf("Allow Write (1/0): ");
    scanf("%d",&writePermission);

    printf("Allow Execute (1/0): ");
    scanf("%d",&executePermission);

    printf("\nPermissions Updated Successfully.\n");
}