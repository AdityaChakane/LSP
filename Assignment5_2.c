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

    printf("Enter the file name : \n");
    scanf("%s",Fname);

    fd = open(Fname, O_RDONLY);

    read(fd, &sobj, sizeof(sobj));

    printf("Roll Number : %d\tName : %s\t Marks : %f\t Age : %d\n", sobj.Rollno, sobj.Sname, sobj.Marks, sobj.Age);

    close(fd);

    return 0;
}