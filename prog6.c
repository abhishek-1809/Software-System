/*
============================================================================
Name : 6.c
Author : Abhishek Sahu
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    char *buffer[20];
    int r,w;

    r = read(STDIN_FILENO,buffer,20);
    if(r == 0)
        exit(EXIT_FAILURE);

    w = write(STDOUT_FILENO,buffer,20);
    if(r == -1 || w == -1)
    {
        perror("read or write error");
        exit(EXIT_FAILURE);
    }

    return 0;
}
/*
Output:
hello world
hello world
*/