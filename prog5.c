/*
============================================================================
Name : 5.c
Author : Abhishek Sahu
Description : Write a program to create five new files with infinite loop. Execute the program in the background
			  and check the file descriptor table at /proc/pid/fd.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fds[5];
    char filename[30];
	int i = 0;

    while (1)
	{
        if (i < 5)
		{
            snprintf(filename, sizeof(filename), "file%d.txt", i + 1);
            fds[i] = open(filename, O_CREAT | O_WRONLY, 0644);
            
            if (fds[i] == -1) { 
                perror("open");
                return 1;
            }

            i++;
        }

		else
            sleep(1);
    }

    return 0;
}
/*
Output:
total 0
lrwx------ 1 abhishek abhishek 64 Aug 29 22:53 0 -> /dev/pts/0
lrwx------ 1 abhishek abhishek 64 Aug 29 22:53 1 -> /dev/pts/0
lr-x------ 1 abhishek abhishek 64 Aug 29 22:53 103 -> /snap/code/167/usr/share/code/v8_context_snapshot.bin
lrwx------ 1 abhishek abhishek 64 Aug 29 22:53 2 -> /dev/pts/0
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 3 -> /home/abhishek/Desktop/hands_on_list1/file1.txt
lr-x------ 1 abhishek abhishek 64 Aug 29 22:53 37 -> /snap/code/167/usr/share/code/resources/app/node_modules.asar
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 38 -> /home/abhishek/.config/Code/logs/20240829T220041/ptyhost.log
lrwx------ 1 abhishek abhishek 64 Aug 29 22:53 39 -> 'socket:[23425]'
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 4 -> /home/abhishek/Desktop/hands_on_list1/file2.txt
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 5 -> /home/abhishek/Desktop/hands_on_list1/file3.txt
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 6 -> /home/abhishek/Desktop/hands_on_list1/file4.txt
l-wx------ 1 abhishek abhishek 64 Aug 29 22:53 7 -> /home/abhishek/Desktop/hands_on_list1/file5.txt
*/