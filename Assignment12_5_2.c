// Client

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<errno.h>

struct my_msg_st
{
    long int my_msg_type;
    char some_text[BUFSIZ];
};

int main()
{
    int Running = 1;
    struct my_msg_st some_data;
    int msgid;
    long int msg_to_receive = 0;
    char Buffer[512];

    msgid = msgget( (key_t)1111, 0666 | IPC_CREAT );

    if(msgid == -1)
    {
        fprintf(stderr, "Failed to create : \n");
        exit(EXIT_FAILURE);
    }

    while(Running)
    {
        msgrcv(msgid, (void*)&some_data, BUFSIZ, msg_to_receive, 0);

        printf("Message : %s", some_data.some_text);
        if(strncmp(Buffer, "end", 3) == 0)
        {
            Running = 0;
        }
    }

    return 0;
}