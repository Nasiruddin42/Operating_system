#include<stdio.h>
#include<pthread.h>

int a[5] = {1,3,4,2,5} ;

void* square(){
    for(int i = 0; i < 5; i++){
        printf("thread-1: Square of %d = %d\n",a[i], a[i]*a[i]) ;
    }
}
void* print(){
    for(int i  = 0; i < 5; i++){
        printf("Thread-2: print %d\n", i) ;
    }
}

int main(){
    pthread_t td1, td2 ;
    pthread_create(&td1,NULL, square, NULL) ;
    pthread_create(&td2, NULL, print, NULL) ;
    pthread_join(td1, NULL) ;
    pthread_join(td2, NULL) ;
}