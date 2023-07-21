#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;
    char cMode[10];
    int mode = 0;

    printf("Enter the file name and mode in which you want to open file : \n");
    scanf("%s %s", Fname, cMode);

    if(strcmp(cMode, "read") == 0)
    {
        mode = R_OK;
    }
    else if(strcmp(cMode, "write") == 0)
    {
        mode = W_OK;
    }
    else if(strcmp(cMode, "execute") == 0)
    {
        mode = X_OK;
    }


    if(access(Fname,mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n", Fname, cMode);
    }
    else
    {
        printf("You can access %s file in %s mode\n", Fname, cMode);
    }

    return 0;
}