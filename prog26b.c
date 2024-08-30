/*
============================================================================
Name : 26b.c
Author : Abhishek Sahu
Description : Write a program to execute an executable program.
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/
#include <unistd.h>

int main()
{
    execl("./a.out", "./a.out", "Alice", (char *)NULL);

    return 0;
}
/*
Output:
Hello World
*/