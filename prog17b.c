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
#include <string.h>
#include <errno.h>

#define TICKET_FILE "ticket.dat"
#define TICKET_SIZE 20

void lock_file(int fd)
{
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("lock_file failed");
        exit(EXIT_FAILURE);
    }
    printf("File locked by process %d\n", getpid());
}

void unlock_file(int fd)
{
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("unlock_file failed");
        exit(EXIT_FAILURE);
    }
    printf("File unlocked by process %d\n", getpid());
}

int main()
{
    int fd;
    char ticket_number[TICKET_SIZE];
    int current_ticket_number;

    fd = open(TICKET_FILE, O_RDWR);
    if (fd == -1)
    {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    lock_file(fd);

    if (pread(fd, ticket_number, sizeof(ticket_number), 0) == -1)
    {
        perror("pread failed");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    current_ticket_number = atoi(ticket_number);

    current_ticket_number++;
    snprintf(ticket_number, sizeof(ticket_number), "%d", current_ticket_number);

    if (pwrite(fd, ticket_number, sizeof(ticket_number), 0) == -1)
    {
        perror("pwrite failed");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("New ticket number: %d\n", current_ticket_number);

    unlock_file(fd);

    close(fd);
    return 0;
}
/*
Output:
File locked by process 31803
New ticket number: 2
File unlocked by process 31803
*/