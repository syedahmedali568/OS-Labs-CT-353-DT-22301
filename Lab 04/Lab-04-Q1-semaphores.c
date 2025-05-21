#include <stdio.h>
#include <semaphore.h>

int main() {
    int buffer[10], bufsize, in, out, produce, consume, choice = 0;
    sem_t mutex, empty, full;
    
    in = 0;
    out = 0;
    bufsize = 10;
    
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, bufsize);
    sem_init(&full, 0, 0);
    
    while(choice != 3) {
        printf("\n1. Produce \t2. Consume \t3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (sem_trywait(&empty) == 0) {
                    sem_wait(&mutex);
                    printf("\nEnter the value: ");
                    scanf("%d", &produce);
                    buffer[in] = produce;
                    in = (in + 1) % bufsize;
                    sem_post(&mutex);
                    sem_post(&full);
                } else {
                    printf("\nBuffer is Full");
                }
                break;
                
            case 2:
                if (sem_trywait(&full) == 0) {
                    sem_wait(&mutex);
                    consume = buffer[out];
                    printf("\nThe consumed value is %d", consume);
                    out = (out + 1) % bufsize;
                    sem_post(&mutex);
                    sem_post(&empty);
                } else {
                    printf("\nBuffer is Empty");
                }
                break;
        }
    }
    
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}