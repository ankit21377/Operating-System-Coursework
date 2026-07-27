#include <stdio.h>

#include "authentication.h"
#include "file_manager.h"
#include "permissions.h"
#include "encryption.h"
#include "audit.h"

int main()
{
    int choice;

    printf("=============================================\n");
    printf(" Task 3 : File System Operations and Security\n");
    printf("=============================================\n");

    if(!login())
    {
        printf("\nAccess Denied!\n");
        return 0;
    }

    do
    {
        printf("\n========== MAIN MENU ==========\n");

        printf("1. Create File\n");
        printf("2. Write File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Display Permissions\n");
        printf("6. Change Permissions\n");
        printf("7. Encrypt File\n");
        printf("8. Decrypt File\n");
        printf("9. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createFile();
                logActivity("File Created");
                break;

            case 2:
                writeFile();
                logActivity("File Modified");
                break;

            case 3:
                readFile();
                logActivity("File Read");
                break;

            case 4:
                deleteFile();
                logActivity("File Deleted");
                break;

            case 5:
                displayPermissions();
                break;

            case 6:
                changePermissions();
                logActivity("Permissions Changed");
                break;

            case 7:
                encryptFile();
                logActivity("File Encrypted");
                break;

            case 8:
                decryptFile();
                logActivity("File Decrypted");
                break;

            case 9:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice.\n");
        }

    } while(choice != 9);

    printf("\nProgram Finished Successfully.\n");

    return 0;
}