#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void* task1(void* arg) {
    for(int i = 0; i < 5; i++) {
        printf("Thread 1: Counting %d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}
void* task2(void* arg) {
    for(int i = 0; i < 5; i++) {
        printf("Thread 2: Counting %d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t t1, t2;
    printf("Main: Creating threads...\n");
    if(pthread_create(&t1, NULL, task1, NULL)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }
    if(pthread_create(&t2, NULL, task2, NULL)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main: Both threads finished execution.\n");
    return 0;
}
