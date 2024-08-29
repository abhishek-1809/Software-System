/*
============================================================================
Name : 10.c
Author : Abhishek Sahu
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data.
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int result;
    int new_offset;

    fd = open("f10.txt", O_RDWR | O_CREAT, 0644);
    if(fd == -1)
    {
        perror("file open");
        exit(EXIT_FAILURE);
    }

    char *c = "viriwofkeh";
    result = write(fd,c,10);
    if(result != 10)
    {
        perror("1st write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    new_offset = lseek(fd,10,SEEK_CUR);
    if(fd == -1)
    {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    c = "ndvieuewiy";
    result = write(fd,c,10);
    if(result != 10)
    {
        perror("2nd write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    printf("Program compiled successfully\n");

    return 0;
}
/*
Output:
Program compiled successfully
*/