#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Inside the thread\n");

    // Detach the thread
    pthread_detach(pthread_self());

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    // Create a new thread
    if (pthread_create(&tid, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Print thread ID of the main thread and the created thread
    printf("Main thread ID: %lu\n", (unsigned long)pthread_self());
    printf("Created thread ID: %lu\n", (unsigned long)tid);

    // Check if two threads are equal (unnecessary and incorrect in this context)
    // if (pthread_equal(tid, pthread_self()))
    //     printf("Threads are equal\n");
    // else
    //     printf("Threads are not equal\n");

    // Instead of joining the detached thread, wait a moment for the detached thread to run
    sleep(1);

    printf("Main thread exiting\n");

    // Exit the main thread
    pthread_exit(NULL);

    return 0;
}
