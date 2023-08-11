#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <pwd.h>

int main()
{
    struct passwd obj;
    struct passwd *ptr = NULL;
    char *cptr = NULL;


    ptr = getpwuid(getuid());

    cptr = ptr->pw_dir;

    printf("Login User name : %s\n", getlogin());
    printf("Home Directory name : %s\n", cptr);

    return 0;
}