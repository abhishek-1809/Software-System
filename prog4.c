/*
============================================================================
Name : 4.c
Author : Abhishek Sahu
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 16th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>

int main(){
	printf("fd = %d\n", open("myfile.txt",O_RDWR|O_EXCL|O_CREAT,0744));
	perror("fd");

	return 0;
}

/*
Output:
fd = 3
fd: Success
*/