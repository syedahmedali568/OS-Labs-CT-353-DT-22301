#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;   // Index for producer
int out = 0;  // Index for consumer

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100 + 1;

        sem_wait(&empty);             // Wait for empty slot
        pthread_mutex_lock(&mutex);   // Lock buffer

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produced: %d | ", item);
        printf("Buffer: ");
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&full);              // Signal item available

        sleep(rand() % 2);            // Random delay
    }
    return NULL;
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);              // Wait for available item
        pthread_mutex_lock(&mutex);   // Lock buffer

        int item = buffer[out];
        buffer[out] = 0;              // Optional: zero out slot for clarity
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumed: %d | ", item);
        printf("Buffer: ");
        for (int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&empty);             // Signal empty slot

        sleep(rand() % 2);            // Random delay
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Run until interrupted
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Clean up (won't be reached in this infinite loop)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
