/*
============================================================================
Name : 17.c
Author : Abhishek Sahu
Description : Write a program to simulate online ticket reservation. Implement write lock
              Write a program to open a file, store a ticket number and exit. Write a separate program, to
              open the file, implement write lock, read the ticket number, increment the number and print
              the new ticket number then close the file.
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TICKET_FILE "ticket.dat"
#define INITIAL_TICKET_NUMBER 1

int main()
{
    int fd;
    const char *filename = TICKET_FILE;
    char ticket_number[10];

    fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    snprintf(ticket_number, sizeof(ticket_number), "%d", INITIAL_TICKET_NUMBER);
    if (write(fd, ticket_number, sizeof(ticket_number)) != sizeof(ticket_number))
    {
        perror("write failed");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Initial ticket number %d written to file.\n", INITIAL_TICKET_NUMBER);

    close(fd);
    return 0;
}
/*
Output:
Initial ticket number 1 written to file
*/