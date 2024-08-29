/*
============================================================================
Name : 9.c
Author : Abhishek Sahu
Description : Write a program to print the following information about a given file.
                a. inode
                b. number of hard links
                c. uid
                d. gid
                e. size
                f. block size
                g. number of blocks
                h. time of last access
                i. time of last modificati
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;

    if(stat("info.txt",&file_stat) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("Inode: %lu\n",(unsigned long)file_stat.st_ino);
    
    printf("No. of hard links: %lu\n",(unsigned long) file_stat.st_nlink);
    
    printf("UID: %u\n",file_stat.st_uid);
    
    printf("GId: %ul\n",file_stat.st_gid);
    
    printf("Size: %ld bytes\n",(long)file_stat.st_size);
    
    printf("Block Size: %ld bytes\n",(long)file_stat.st_blksize);
    
    printf("No. of blocks: %ld\n",(long)file_stat.st_blocks);

    printf("Time of last access: %s",ctime(&file_stat.st_atime));
    
    printf("Time of last modification: %s",ctime(&file_stat.st_mtime));

    printf("Time of last change: %s",ctime(&file_stat.st_ctime));
    

    return 0;
}

/*
Output:
Inode: 3671437
No. of hard links: 1
UID: 1000
GId: 1000l
Size: 77 bytes
Block Size: 4096 bytes
No. of blocks: 8
Time of last access: Tue Aug 27 17:42:10 2024
Time of last modification: Tue Aug 27 17:39:50 2024
Time of last change: Tue Aug 27 17:39:50 2024
*/