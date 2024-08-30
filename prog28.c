/*
============================================================================
Name : 28.c
Author : Abhishek Sahu
Description : Write a program to get maximum and minimum real time priority.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>

int main()
{
    int maxp_fifo, minp_fifo;
    int maxp_rr, minp_rr;

    maxp_fifo = sched_get_priority_max(SCHED_FIFO);
    if (maxp_fifo == -1)
    {
        perror("sched_get_priority_max (SCHED_FIFO) failed");
        exit(EXIT_FAILURE);
    }

    minp_fifo = sched_get_priority_min(SCHED_FIFO);
    if (minp_fifo == -1)
    {
        perror("sched_get_priority_min (SCHED_FIFO) failed");
        exit(EXIT_FAILURE);
    }

    maxp_rr = sched_get_priority_max(SCHED_RR);
    if (maxp_rr == -1)
    {
        perror("sched_get_priority_max (SCHED_RR) failed");
        exit(EXIT_FAILURE);
    }

    minp_rr = sched_get_priority_min(SCHED_RR);
    if (minp_rr == -1)
    {
        perror("sched_get_priority_min (SCHED_RR) failed");
        exit(EXIT_FAILURE);
    }

    printf("Real-time priorities:\n");
    printf("SCHED_FIFO: Min = %d, Max = %d\n", minp_fifo, maxp_fifo);
    printf("SCHED_RR: Min = %d, Max = %d\n", minp_rr, maxp_rr);

    return 0;
}
/*
Output:
Real-time priorities:
SCHED_FIFO: Min = 1, Max = 99
SCHED_RR: Min = 1, Max = 99
*/