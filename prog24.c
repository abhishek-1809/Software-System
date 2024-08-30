/*
============================================================================
Name : 24.c
Author : Abhishek Sahu
Description : Write a program to create an orphan process.
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
        
        sleep(10);
        
        printf("Orphan Child Process: PID = %d, New Parent PID = %d\n", getpid(), getppid());
        exit(EXIT_SUCCESS);
    }
    
    else
    {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        
        sleep(2);
        
        printf("Parent Process: Terminating...\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}
/*
Output:
Parent Process: PID = 14346, Child PID = 14347
Child Process: PID = 14347, Parent PID = 14346
Parent Process: Terminating...
*/