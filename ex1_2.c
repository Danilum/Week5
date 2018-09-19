//
//  main.c
//  Week5 Task1.2
//
//  Created by Daniil Shilintsev on 19/09/2018.
//  Copyright © 2018 Daniil Shilintsev. All rights reserved.
//

// Sequential
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 3
int thread_id[N];

void *helloFromThread() {
    printf("Hello from thread with ID: %d\n", (int) pthread_self());
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int rc;
    for (int i = 0; i < N; i++) {
        rc = pthread_create(&thread_id[i], NULL, helloFromThread, NULL);
        pthread_join(thread_id[i], NULL);
//        t = pthread_creat()
        if (rc) {
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }
        
        printf("Thread with ID: %d created by thread with ID: %lu\n", (int) thread_id[i], (int) pthread_self());
    }
//    sleep(5)
    pthread_exit(NULL);
}
