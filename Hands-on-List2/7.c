/*
================================================================================
Name : 7.c
Author : Abhishek Sahu
Description : Write a simple program to print the created thread ids.
Date : 16th Sep, 2024
================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    pthread_t thread_id = pthread_self(); 
    printf("Thread ID: %lu\n", thread_id); 
    pthread_exit(NULL); 
}

int main() {
    pthread_t threads[3];
    int i;

    for (i = 0; i < 3; i++) {
        int result = pthread_create(&threads[i], NULL, thread_function, NULL);
        
        if (result != 0) {
            printf("Error creating thread %d\n", i + 1);
            return 1;
        }
    }

    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}

/*
=========================================
Output-

Thread ID: 129734186895040
Thread ID: 129734176409280
Thread ID: 129734165923520
All threads completed.
=========================================
*/