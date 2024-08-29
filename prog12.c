/*
============================================================================
Name : 12.c
Author : Abhishek Sahu
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd,flags;

    fd = open("f10.txt",O_RDWR | O_CREAT | O_EXCL, 0644);
    
    flags = O_RDWR | O_CREAT | O_EXCL;

    printf("File opening modes:\n");
    if (flags & O_RDONLY) printf("  Read-only\n");
    if (flags & O_WRONLY) printf("  Write-only\n");
    if (flags & O_RDWR)   printf("  Read/Write\n");
    if (flags & O_CREAT)  printf("  Create if not exists\n");
    if (flags & O_APPEND) printf("  Append mode\n");
    if (flags & O_TRUNC)  printf("  Truncate file to zero length\n");
    if (flags & O_EXCL)   printf("  Exclusive creation\n");
    if (flags & O_NONBLOCK) printf("  Non-blocking mode\n");
    if (flags & O_SYNC)   printf("  Synchronous writes\n");
    if (flags & O_DSYNC)  printf("  Synchronous data writes\n");

    return 0;
}
/*
Output:
File opening modes:
  Read/Write
  Create if not exists
  Exclusive creation
*/