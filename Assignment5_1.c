#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0;

    sobj.Rollno = 1;
    sobj.Marks = 90.66f;
    sobj.Age = 20;
    strcpy(sobj.Sname,"Aditya");

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = creat(Fname,0777);

    write(fd,&sobj,sizeof(sobj));

    return 0;
}