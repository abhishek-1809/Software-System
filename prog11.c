/*
============================================================================
Name : 11.c
Author : Abhishek Sahu
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
              descriptors and check whether the file is updated properly or not.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd,fd_dup,fd_dup2,fd_fcntl;

    fd = open("myfile.txt",O_WRONLY | O_APPEND | O_CREAT, 0677);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_dup = dup(fd);
    if (fd == -1)
    {
        perror("dup");
        close(fd);
        exit(EXIT_FAILURE);
    }

    fd_dup2 = dup2(fd,53);
    if (fd == -1)
    {
        perror("dup2");
        close(fd);
        close(fd_dup);
        exit(EXIT_FAILURE);
    }

    fd_fcntl = fcntl(fd,F_DUPFD,170);
    if (fd == -1)
    {
        perror("fcntl");
        close(fd);
        close(fd_dup);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }

    if (write(fd, "original descriptor",19) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    if (write(fd_dup, "\nduplicate descriptor", 21) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    if (write(fd_dup2, "\nduplicate descriptor", 21) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    if (write(fd_fcntl, "\nduplicate descriptor", 21) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    close(fd);
    close(fd_dup);
    close(fd_dup2);
    close(fd_fcntl);

    fd = open("myfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    return 0;
}
/*
Output:
original descriptor
duplicate descriptor
duplicate descriptor
duplicate descriptor
*/