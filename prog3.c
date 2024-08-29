/*
============================================================================
Name : 3.c
Author : Abhishek Sahu
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	printf("fd = %d\n", creat("myfile.txt", 0744));

	return 0;
}

/*
Output:
fd = 3
*/