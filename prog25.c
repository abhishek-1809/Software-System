/*
============================================================================
Name : 25.c
Author : Abhishek Sahu
Description : Write a program to create three child processes. The parent should wait for a particular child (use
              waitpid system call).
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3;
    pid_t child_pid;
    int status;
    
    if ((pid1 = fork()) < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    else if (pid1 == 0)
    {
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(3);
        exit(1);
    }

    if ((pid2 = fork()) < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    else if (pid2 == 0)
    {
        printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(5);
        exit(2);
    }

    if ((pid3 = fork()) < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    else if (pid3 == 0)
    {
        printf("Child 3: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(7);
        exit(3);
    }

    printf("Parent Process: PID = %d\n", getpid());

    child_pid = waitpid(pid2, &status, 0);
    if (child_pid == -1)
    {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status))
        printf("Parent Process: Child %d exited with status %d\n", child_pid, WEXITSTATUS(status));
    
    else
        printf("Parent Process: Child %d did not terminate normally\n", child_pid);

    while ((child_pid = wait(&status)) > 0)
    {
        if (WIFEXITED(status))
            printf("Parent Process: Child %d exited with status %d\n", child_pid, WEXITSTATUS(status));
        
        else 
            printf("Parent Process: Child %d did not terminate normally\n", child_pid);
    }
    return 0;
}
/*
Output:
Child 1: PID = 14574, Parent PID = 14573
Child 2: PID = 14575, Parent PID = 14573
Parent Process: PID = 14573
Child 3: PID = 14576, Parent PID = 14573
Parent Process: Child 14575 exited with status 2
Parent Process: Child 14574 exited with status 1
Parent Process: Child 14576 exited with status 3
*/