/*
============================================================================
Name : 1c.c
Author : Abhishek Sahu
Description : Create the following types of files using (i) shell command (ii) system call
                       c. FIFO (mkfifo Library Function or mknod system call)
Date: 16th Aug, 2024.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	const char *fifo = "myfifo";

	if(mkfifo(fifo,0666) == -1){
		perror("mkfifo");
		return 1;
	}
	printf("FIFO created successfully.");
	return 0;
}

/*
Output:
FIFO created successfully.
*/