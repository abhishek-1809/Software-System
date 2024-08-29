/*
============================================================================
Name : 13.c
Author : Abhishek Sahu
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<sys/select.h>
#include<errno.h>


int main()
{
    fd_set read;
    struct timeval timeout;
    int result;

    FD_ZERO(&read);
    FD_SET(STDIN_FILENO, &read);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    result = select(STDIN_FILENO + 1, &read, NULL, NULL, &timeout);

    if (result == -1)
    {
        perror("select");
        return EXIT_FAILURE;
    }
    else if (result == 0)
        printf("No input received within 10 seconds.\n");
    
    else
    {
        if (FD_ISSET(STDIN_FILENO, &read))
            printf("Input is available on stdin.\n");
        
    }

    return 0;
}
/*
Output:
hello world
Input is available on stdin.
*/