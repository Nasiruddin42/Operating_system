#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<limits.h>

int cnt ;
int *numbers ;
int mx_value ;
int mn_value ;

void* mx(void *arg){
    mx_value = INT_MIN ;
    for(int i = 0; i < cnt; i++){
        if(numbers[i] > mx_value){
            mx_value = numbers[i] ;
        }
    }
    printf("mx : %d\n", mx_value) ;
}
void* mn(void *arg){
    mn_value = INT_MAX ;
    for(int i = 0; i < cnt; i++){
        if(numbers[i] < mn_value){
            mn_value = numbers[i] ;
        }
    }
    printf("mn : %d\n", mn_value) ;
}

int main(int argc, char *argv[]){

    cnt = argc - 2 ;
    numbers = (int*)malloc(cnt * sizeof(int)) ;

    for(int i = 2; i < argc; i++){
        numbers[i-2] = atoi(argv[i]) ;
    }

    pthread_t td1, td2,td3 ;
    pthread_create(&td1, NULL, mx, NULL) ;
    pthread_create(&td2, NULL, mn, NULL) ;
    //pthread_create(td3, NULL, avg, NULL) ;

    pthread_join(td1, NULL) ;
    pthread_join(td2, NULL) ;
    //pthread_join(td3, NULL) ;
    
}