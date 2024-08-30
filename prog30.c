/*
============================================================================
Name : 30.c
Author : Abhishek Sahu
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    if(!fork())
    {
        setsid();
        chdir("/");
        umask(0);
        while(1)
        {
            sleep(4);
            printf("Child pid: %d\n",getpid());
            printf("Daemon process is running....\n");
        }
    }

    else
        exit(0);
}
/*
Output:
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
Child pid: 29792
Daemon process is running....
*/