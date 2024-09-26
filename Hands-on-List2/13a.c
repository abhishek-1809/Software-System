/*
================================================================================
Name : 13a.c
Author : Abhishek Sahu
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date : 18th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught SIGINT (Ctrl+C), but still running...\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Process (PID: %d) is waiting for SIGSTOP...\n", getpid());

    while (1){
        // pause(); 
    }

    return 0;
}

/*
=========================================
Output-

Process (PID: 12170) is waiting for SIGSTOP...

[1]+  Stopped                 ./a.out
=========================================
*/