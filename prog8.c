/*
============================================================================
Name : 8.c
Author : Abhishek Sahu
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
			  Close the file when end of file is reached.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	FILE *fptr;
	char buffer[1024];

	fptr = fopen("f1.txt","r");

	while(fgets(buffer,sizeof(buffer),fptr) != NULL){
		printf("%s",buffer);
		sleep(1);
	}

	fclose(fptr);
	return 0;
}
/*
Output:
Hello
This program will open a file in read only mode and,
read line by line and display each line as it is read.
*/