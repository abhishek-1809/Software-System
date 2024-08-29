/*
============================================================================
Name : 1b.c
Author : Abhishek Sahu
Description : Create the following types of files using (i) shell command (ii) system call
                       b. hard link (link system call)
Date: 29th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main(){
	const char *target = "target.txt";
	const char *hardlink = "hardlink.txt";

	if(link(target,hardlink) == -1){
		perror("link");
		return 1;
	}
	printf("Hard link created successfully.\n");

	return 0;
}

/*
============================================================================
Output:
Hard link created successfully.
============================================================================
*/