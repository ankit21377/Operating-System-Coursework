#include <stdio.h>
#include <stdlib.h>
#include "file_manager.h"

void createFile()
{
    char filename[100];

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("File Creation Failed.\n");
        return;
    }

    printf("File Created Successfully.\n");

    fclose(fp);
}

void writeFile()
{
    char filename[100];
    char data[500];

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename, "a");

    if(fp == NULL)
    {
        printf("Unable to Open File.\n");
        return;
    }

    getchar();

    printf("Enter Text: ");
    fgets(data, sizeof(data), stdin);

    fprintf(fp,"%s",data);

    fclose(fp);

    printf("Data Written Successfully.\n");
}

void readFile()
{
    char filename[100];
    char ch;

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename,"r");

    if(fp == NULL)
    {
        printf("File Not Found.\n");
        return;
    }

    printf("\n========== FILE CONTENT ==========\n");

    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}

void deleteFile()
{
    char filename[100];

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    if(remove(filename)==0)
        printf("File Deleted Successfully.\n");
    else
        printf("Unable to Delete File.\n");
}