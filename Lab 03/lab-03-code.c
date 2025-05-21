#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func1(void *ptr);
void *func2(void *ptr);
main()
{
pthread_t thread1, thread2;
char *message1 = "Thread 1";
char *message2 = "Thread 2";
int iret1, iret2;

iret1 = pthread_create( &thread1, NULL, func1,
(void*) message1);
iret2 = pthread_create( &thread2, NULL, func2,
(void*) message1);

pthread_join( thread1, NULL);
pthread_join( thread2, NULL);
printf("\n\nThread 1 returns: %d\n"

,iret1);

printf("\nThread 2 returns: %d\n"

,iret2);

exit(0);
}

void *func1(void *ptr) {
for (int i = 0; i < 6; i++) {
printf("\nfunc1 %d"
, i);

sleep(1);
}
}

void *func2(void *ptr) {
for (int i = 0; i < 6; i++) {
printf("\nfunc2 %d"
, i);

sleep(3);
}
}
void *func1(void *ptr) {
for (int i = 0; i < 6; i++) {
printf("\nfunc1 %d"
, i);

sleep(1);
}
}

void *func2(void *ptr) {
for (int i = 0; i < 6; i++) {
printf("\nfunc2 %d"
, i);

sleep(3);
}
}