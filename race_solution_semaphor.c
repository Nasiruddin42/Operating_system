#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int x = 0;
sem_t semaphore ;

void* sum(){
    for(int i = 0; i < 10; i++){
        sem_wait(&semaphore) ;
        x = x + 1 ;
        printf("Thread-1: sum of x + 1 = %d\n", x) ;
        sem_post(&semaphore) ;
    }
}
void* sub(){
    for(int i = 0; i < 10; i++){
        sem_wait(&semaphore) ;
        x = x - 1 ;
        printf("Thread-2: sub of x - 1 = %d\n", x) ;
        sem_post(&semaphore) ;
    }
}

int main(){
    sem_init(&semaphore, 0, 1) ;
        pthread_t td1, td2 ;
        pthread_create(&td1, NULL, sum, NULL) ;
        pthread_create(&td2, NULL, sub, NULL) ;

        pthread_join(td1, NULL) ;
        pthread_join(td2, NULL) ;
    sem_destroy(&semaphore) ;
}