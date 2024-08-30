/*
============================================================================
Name : 22.c
Author : Abhishek Sahu
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid;
    int fd;
    const char *filename = "file22.txt";
    
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) 
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    else if (pid == 0) 
    {
        const char *child_msg = "This is the child process writing to the file.\n";
        if (write(fd, child_msg, sizeof(child_msg) - 1) < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        printf("Child process wrote to the file.\n");
        close(fd);
        exit(EXIT_SUCCESS);
    }

    else 
    {
        const char *parent_msg = "This is the parent process writing to the file.\n";

        if (write(fd, parent_msg, sizeof(parent_msg) - 1) < 0) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Parent process wrote to the file.\n");
        close(fd);

        wait(NULL);
    }

    return 0;
}
/*
Output:
Parent process wrote to the file.
Child process wrote to the file.
*/