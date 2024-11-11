#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int x = 0 ;
pthread_mutex_t mutex ;

void* sum(){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutex) ;
        x = x + 1;
        printf("Thread-1: summation of x + 1 :%d\n", x) ;
        pthread_mutex_unlock(&mutex) ;
    }
}
void* sub(){
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&mutex) ;
        x = x - 1;
        printf("Thread-1: subtraction of x - 1 :%d\n", x) ;
        pthread_mutex_unlock(&mutex) ;
    }
}


int main(){
    pthread_mutex_init(&mutex, NULL) ;
        pthread_t td1, td2 ;
        pthread_create(&td1, NULL, sum, NULL) ;
        pthread_create(&td2, NULL, sub, NULL) ;

        pthread_join(td1, NULL) ;
        pthread_join(td2, NULL) ;
    pthread_mutex_destroy(&mutex) ;

}