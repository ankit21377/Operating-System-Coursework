#include <stdio.h>
#include <string.h>
#include "authentication.h"

int login()
{
    char username[100];
    char password[50];

    printf("\n=========== LOGIN ===========\n");

    printf("Username: ");
    scanf("%99s", username);

    printf("Password: ");
    scanf("%49s", password);

    if(strcmp(username, USERNAME) == 0 &&
       strcmp(password, PASSWORD) == 0)
    {
        printf("\nLogin Successful.\n");
        return 1;
    }

    printf("\nInvalid Username or Password.\n");
    return 0;
}