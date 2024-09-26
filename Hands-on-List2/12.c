/*
================================================================================
Name : 12.c
Author : Abhishek Sahu
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    int pid = fork(); 

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } 
    else if (pid > 0) {
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
     
        sleep(2);

        printf("Parent is exiting...\n");
        exit(0);
    } 
    else {
        sleep(1);  

        printf("Child (PID: %d) sending SIGKILL to Parent (PID: %d)\n", getpid(), getppid());
        kill(getppid(), SIGKILL);

        printf("Child process continues running...\n");
        sleep(5);  
    }

    return 0;
}

/*
=========================================
Output-

Parent PID: 7797
Child PID: 7798
Child (PID: 7798) sending SIGKILL to Parent (PID: 7797)
Child process continues running...
Killed
=========================================
*/