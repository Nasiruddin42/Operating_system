#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int x = 0 ;

void* sum(){
    for(int i = 0; i < 10; i++){
        x = x + 1 ;
        printf("Thread-1: summation of x + 1 = %d\n", x) ;
    }
}
void* sub(){
    for(int i = 0; i < 10; i++){
        x = x - 1 ;
        printf("Thread-2: subtraction of x - 1 = %d\n", x) ;
    }
}

int main(){
    pthread_t td1, td2 ;
    pthread_create(&td1, NULL, sum, NULL) ;
    pthread_create(&td2, NULL, sub, NULL) ;

    pthread_join(td1, NULL) ;
    pthread_join(td2, NULL) ;
}