// Server

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<errno.h>

#define MAX_TEXT 512

struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};

int main()
{
    int Running = 1;
    struct my_msg_st some_data;
    int msgid;
    char Buffer[BUFSIZ];

    msgid = msgget( (key_t)1111, 0666 | IPC_CREAT );

    if(msgid == -1)
    {
        fprintf(stderr, "Failed to create : \n");
        exit(EXIT_FAILURE);
    }

    while(Running)
    {
        printf("Enter message : ");
        fgets(Buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, Buffer);

        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }

        if(strncmp(Buffer, "end", 3) == 0)
        {
            Running = 0;
        }
    }

    return 0;
}