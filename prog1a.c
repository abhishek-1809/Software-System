/*
============================================================================
Name : 1a.c
Author : Abhishek Sahu
Description : Create the following types of files using (i) shell command (ii) system call
                       a. soft link (symlink system call)
Date: 16th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
	const char *target = "target.txt";
	const char *linkpath  = "symlink.txt";

 	if (symlink(target, linkpath) == -1){
  		perror("symlink");
  		return 1;
 	}
	printf("Soft link created successfully.\n");

return 0;
}

/*
============================================================================
Output:
Soft link created successfully.
============================================================================
*/