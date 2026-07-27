#include <stdio.h>
#include "encryption.h"

#define KEY 3

void encryptFile()
{
    char filename[100];
    char ch;

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename,"r+");

    if(fp==NULL)
    {
        printf("File Not Found.\n");
        return;
    }

    while((ch=fgetc(fp))!=EOF)
    {
        fseek(fp,-1,SEEK_CUR);
        fputc(ch+KEY,fp);
        fflush(fp);
    }

    fclose(fp);

    printf("File Encrypted Successfully.\n");
}

void decryptFile()
{
    char filename[100];
    char ch;

    printf("\nEnter File Name: ");
    scanf("%99s", filename);

    FILE *fp = fopen(filename,"r+");

    if(fp==NULL)
    {
        printf("File Not Found.\n");
        return;
    }

    while((ch=fgetc(fp))!=EOF)
    {
        fseek(fp,-1,SEEK_CUR);
        fputc(ch-KEY,fp);
        fflush(fp);
    }

    fclose(fp);

    printf("File Decrypted Successfully.\n");
}