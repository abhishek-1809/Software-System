/*
============================================================================
Name : 20.c
Author : Abhishek Sahu
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

void print_priority()
{
    int priority = getpriority(PRIO_PROCESS, 0);
    if (priority == -1 && errno != 0)
    {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }

    printf("Priority of process : %d\n", priority);
}

void modify_priority(int increment)
{
    int new_priority = getpriority(PRIO_PROCESS, 0) + increment;
    
    if(new_priority > 19)
        new_priority = 19;
    
    else if(new_priority < -20)
        new_priority = -20;
    
    if(setpriority(PRIO_PROCESS, 0, new_priority) == -1)
    {
        perror("setpriority");
        exit(EXIT_FAILURE);
    }

    printf("Priority changed to: %d\n", new_priority);
}

int main()
{
    printf("process PID: %d\n", getpid());

    print_priority();

    int increment = 5;
    modify_priority(increment);

    printf("Priority is modified by %d...\n", increment);

    print_priority();

    return 0;
}
/*
Output:
process PID: 12318
Priority of process : 0
Priority changed to: 5
Priority is modified by 5...
Priority of process : 5
*/