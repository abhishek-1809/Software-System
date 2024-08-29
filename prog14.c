/*
============================================================================
Name : 14.c
Author : Abhishek Sahu
Description : Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void file_type(mode_t mode)
{
    if (S_ISREG(mode))
        printf("Regular file\n");

    else if (S_ISDIR(mode))
        printf("Directory\n");
    
    else if (S_ISCHR(mode))
        printf("Character device\n");
    
    else if (S_ISBLK(mode))
        printf("Block device\n");
    
    else if (S_ISFIFO(mode))
        printf("FIFO (named pipe)\n");
    
    else if (S_ISLNK(mode))
        printf("Symbolic link\n");
    
    else if (S_ISSOCK(mode))
        printf("Socket\n");
    
    else
        printf("Unknown file type\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Wrong argument entered\n");
        return EXIT_FAILURE;
    }

    const char *file = argv[1];
    struct stat file_stat;

    if (stat(file, &file_stat) == -1)
    {
        perror("stat");
        return EXIT_FAILURE;
    }

    file_type(file_stat.st_mode);

    return EXIT_SUCCESS;
}
/*
Output:

./prog14 myfifo
FIFO (named pipe)
*/