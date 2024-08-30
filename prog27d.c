/*
============================================================================
Name : 27d.c
Author : Abhishek Sahu
Description : Write a program to execute ls -Rl by the following system calls
                a. execv
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        printf("\nUsing execv:\n");

        char *args[] = {"ls", "-Rl", NULL};

        execv("/bin/ls", args);

        perror("execv failed");
        exit(1);
    }
    wait(NULL);

    return 0;
}
/*
Output:
Using execv:
.:
total 664
-rwxrwxr-x 1 abhishek abhishek 15960 Aug 30 14:58 a.out
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 23:00 f10.txt
-rw-rw-r-- 1 abhishek abhishek   114 Aug 29 22:39 f1.txt
-rw-rw-r-- 1 abhishek abhishek   503 Aug 29 22:34 f2.txt
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 22:52 file1.txt
-rw-r--r-- 1 abhishek abhishek    14 Aug 30 00:41 file22.txt
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 22:52 file2.txt
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 22:52 file3.txt
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 22:52 file4.txt
-rw-r--r-- 1 abhishek abhishek     0 Aug 29 22:52 file5.txt
-rw-rw-r-- 2 abhishek abhishek    12 Aug 23 11:55 hardlink.txt
-rw-rw-r-- 1 abhishek abhishek    77 Aug 27 17:39 info.txt
prw-rw-r-- 1 abhishek abhishek     0 Aug 23 11:59 myfifo
-rw-rwxr-x 1 abhishek abhishek    82 Aug 29 23:34 myfile.txt
-rwxrwxr-x 1 abhishek abhishek 16208 Aug 29 10:59 prog10
-rw-rw-r-- 1 abhishek abhishek  1397 Aug 29 22:59 prog10.c
-rwxrwxr-x 1 abhishek abhishek 16248 Aug 29 23:34 prog11
-rw-rw-r-- 1 abhishek abhishek  2029 Aug 29 23:34 prog11.c
-rwxrwxr-x 1 abhishek abhishek 15992 Aug 29 22:40 prog12
-rw-rw-r-- 1 abhishek abhishek  1238 Aug 29 23:00 prog12.c
-rwxrwxr-x 1 abhishek abhishek 16088 Aug 29 19:11 prog13
-rw-rw-r-- 1 abhishek abhishek  1173 Aug 29 23:03 prog13.c
-rwxrwxr-x 1 abhishek abhishek 16120 Aug 29 19:35 prog14
-rw-rw-r-- 1 abhishek abhishek  1449 Aug 29 23:06 prog14.c
-rwxrwxr-x 1 abhishek abhishek 16024 Aug 29 23:22 prog15
-rw-rw-r-- 1 abhishek abhishek  5606 Aug 29 23:24 prog15.c
-rwxrwxr-x 1 abhishek abhishek 16032 Aug 30 00:07 prog19
-rw-rw-r-- 1 abhishek abhishek   830 Aug 30 00:07 prog19.c
-rwxrwxr-x 1 abhishek abhishek 16040 Aug 29 10:03 prog1a
-rw-rw-r-- 1 abhishek abhishek   836 Aug 29 10:06 prog1a.c
-rwxrwxr-x 1 abhishek abhishek 16000 Aug  9 19:25 prog1b
-rw-rw-r-- 1 abhishek abhishek   819 Aug 29 10:07 prog1b.c
-rwxrwxr-x 1 abhishek abhishek 16000 Aug  9 19:49 prog1c
-rw-rw-r-- 1 abhishek abhishek   691 Aug 29 22:05 prog1c.c
-rwxrwxr-x 1 abhishek abhishek 16000 Aug 23 12:26 prog2
-rwxrwxr-x 1 abhishek abhishek 16312 Aug 30 00:19 prog20
-rw-rw-r-- 1 abhishek abhishek  1444 Aug 30 00:20 prog20.c
-rwxrwxr-x 1 abhishek abhishek 16208 Aug 30 00:34 prog21
-rw-rw-r-- 1 abhishek abhishek   929 Aug 30 00:36 prog21.c
-rwxrwxr-x 1 abhishek abhishek 16248 Aug 30 00:41 prog22
-rw-rw-r-- 1 abhishek abhishek  1726 Aug 30 00:46 prog22.c
-rwxrwxr-x 1 abhishek abhishek 16288 Aug 30 00:49 prog23
-rw-rw-r-- 1 abhishek abhishek  1423 Aug 30 00:50 prog23.c
-rwxrwxr-x 1 abhishek abhishek 16248 Aug 30 00:52 prog24
-rw-rw-r-- 1 abhishek abhishek  1166 Aug 30 00:53 prog24.c
-rwxrwxr-x 1 abhishek abhishek 16344 Aug 30 00:57 prog25
-rw-rw-r-- 1 abhishek abhishek  2340 Aug 30 00:59 prog25.c
-rwxrwxr-x 1 abhishek abhishek 16000 Aug 30 13:48 prog26a
-rw-rw-r-- 1 abhishek abhishek   425 Aug 30 14:59 prog26a.c
-rwxrwxr-x 1 abhishek abhishek 15952 Aug 30 14:58 prog26b
-rw-rw-r-- 1 abhishek abhishek   528 Aug 30 14:59 prog26b.c
-rwxrwxr-x 1 abhishek abhishek 16384 Aug 30 15:02 prog27
-rwxrwxr-x 1 abhishek abhishek 16160 Aug 30 15:05 prog27a
-rw-rw-r-- 1 abhishek abhishek  4843 Aug 30 15:12 prog27a.c
-rwxrwxr-x 1 abhishek abhishek 16160 Aug 30 15:09 prog27b
-rw-rw-r-- 1 abhishek abhishek  4953 Aug 30 15:10 prog27b.c
-rw-rw-r-- 1 abhishek abhishek  1686 Aug 30 15:02 prog27.c
-rwxrwxr-x 1 abhishek abhishek 16160 Aug 30 15:12 prog27c
-rw-rw-r-- 1 abhishek abhishek  5085 Aug 30 15:13 prog27c.c
-rwxrwxr-x 1 abhishek abhishek 16216 Aug 30 15:14 prog27d
-rw-rw-r-- 1 abhishek abhishek   680 Aug 30 15:14 prog27d.c
-rw-rw-r-- 1 abhishek abhishek  2245 Aug 29 22:13 prog2.c
-rwxrwxr-x 1 abhishek abhishek 16000 Aug 29 10:12 prog3
-rw-rw-r-- 1 abhishek abhishek   523 Aug 29 10:13 prog3.c
-rwxrwxr-x 1 abhishek abhishek 16040 Aug 29 22:14 prog4
-rw-rw-r-- 1 abhishek abhishek   497 Aug 29 22:16 prog4.c
-rwxrwxr-x 1 abhishek abhishek 16136 Aug 29 22:52 prog5
-rw-rw-r-- 1 abhishek abhishek  1995 Aug 29 22:56 prog5.c
-rwxrwxr-x 1 abhishek abhishek 16128 Aug 29 22:32 prog6
-rw-rw-r-- 1 abhishek abhishek   715 Aug 29 22:33 prog6.c
-rwxrwxr-x 1 abhishek abhishek 16080 Aug 29 22:34 prog7
-rw-rw-r-- 1 abhishek abhishek   613 Aug 29 22:35 prog7.c
-rwxrwxr-x 1 abhishek abhishek 16176 Aug 29 22:39 prog8
-rw-rw-r-- 1 abhishek abhishek   780 Aug 29 22:39 prog8.c
-rw-rw-r-- 1 abhishek abhishek  1770 Aug 29 10:47 prog9.c
lrwxrwxrwx 1 abhishek abhishek    10 Aug 29 10:03 symlink.txt -> target.txt
-rw-rw-r-- 2 abhishek abhishek    12 Aug 23 11:55 target.txt
*/