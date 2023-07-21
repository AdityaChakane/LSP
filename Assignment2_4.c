#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char Dname[20];

    printf("Enter the name of directory\n");
    scanf("%s", Dname);

    dp = opendir(Dname);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("--------------------------------------------------------------------------------------------\n");
    printf("Entries from the directory are : \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf("File Name\t\t File Type\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s : %d\n", entry->d_name, entry->d_type);
    }

    printf("--------------------------------------------------------------------------------------------\n");

    closedir(dp);

    return 0;
}