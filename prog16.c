/*
============================================================================
Name : 16.c
Author : Abhishek Sahu
Description : Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void acquire_read_lock(int fd)
{
    struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("acquire_read_lock failed");
        exit(EXIT_FAILURE);
    }
    printf("Read lock acquired by process %d\n", getpid());
}

void release_lock(int fd)
{
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLK, &lock) == -1)
    {
        perror("release_lock failed");
        exit(EXIT_FAILURE);
    }
    printf("Lock released by process %d\n", getpid());
}

void acquire_write_lock(int fd)
{
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("acquire_write_lock failed");
        exit(EXIT_FAILURE);
    }
    printf("Write lock acquired by process %d\n", getpid());
}

int main()
{
    int fd;
    const char *filename = "testfile.txt";

    fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    acquire_read_lock(fd);

    printf("Press enter to release lock");
    getchar();

    release_lock(fd);
    printf("Attempting to acquire write lock...\n");
    
    acquire_write_lock(fd);
    
    printf("Press enter to release lock");
    getchar();

    release_lock(fd);
    
    close(fd);

    return 0;
}
/*
Output:
Read lock acquired by process 30776
Press enter to release lock
Lock released by process 30776
Attempting to acquire write lock...
Write lock acquired by process 30776
Press enter to release lock
Lock released by process 30776
*/
