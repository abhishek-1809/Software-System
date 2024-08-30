/*
============================================================================
Name : 19.c
Author : Abhishek Sahu
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<fcntl.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(void)
{
    int i, nano;
    unsigned long long int start, end;
    start = rdtsc();

    for(i = 0; i <= 10000; i++)
        getppid();
    
    end = rdtsc();
    nano = (end-start)/2.10;
    printf(" The function takes %d nano sec\n",nano);

    return 0;
}

/*
Output:
The function takes 5489790 nano sec
*/