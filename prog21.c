/*
============================================================================
Name : 21.c
Author : Abhishek Sahu
Description : Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
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
        exit(EXIT_SUCCESS);
    }
    
    else
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL);
    }

    return 0;
}
/*
Output:
Parent Process: PID = 13365, Child PID = 13367
Child Process: PID = 13367, Parent PID = 13365
*/