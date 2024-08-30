/*
============================================================================
Name : 23.c
Author : Abhishek Sahu
Description : Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    else if (pid == 0)
    {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        sleep(2);

        printf("Child Process: Exiting...\n");
        exit(EXIT_SUCCESS);
    }
    
    else
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        printf("Parent Process: Sleeping for 10 seconds to create a zombie...\n");

        sleep(10);

        printf("Parent Process: Calling wait to clean up...\n");
        wait(NULL);
        printf("Parent Process: Child process cleaned up. Exiting...\n");
    }

    return 0;
}
/*
Output:
Parent Process: PID = 14052, Child PID = 14053
Parent Process: Sleeping for 10 seconds to create a zombie...
Child Process: PID = 14053, Parent PID = 14052
Child Process: Exiting...
Parent Process: Calling wait to clean up...
Parent Process: Child process cleaned up. Exiting...
*/