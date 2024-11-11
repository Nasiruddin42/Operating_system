#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>

void signal_handler(int signal){
    if(signal == SIGKILL){
        printf("Thread-1: Received a SIGUSR1 signal from Thread-1\n") ;
        sleep(1) ;
        for(int i = 0; i < 3; i++){
            printf("Thread-1 : Terminating...\n") ;
            sleep(2) ;
        }
        printf("Thread-1 : Terminated\n") ;
        pthread_exit(NULL) ;
    }
}

void* thread_handler_1(){
    signal(SIGKILL, signal_handler) ;

    for(int i = 0; i < 100; i++){
        printf("Thread-1 : Waiting...\n") ;
        sleep(2) ;
    }
}

void* thread_handler_2(void *arg){
    pthread_t *pid = (pthread_t*) arg ;
    printf("Thread-2: sending a SIGUSR1 signal to Thread-1\n") ;

    for(int i = 0; i < 3; i++){
        printf("Thread-2: Sending...\n") ;
        sleep(2) ;
    }
    printf("Thread-2: Sent signal\n") ;
    pthread_kill(*pid, SIGKILL) ;
}


int main(){
    pthread_t td1, td2 ;
    pthread_create(&td1, NULL, thread_handler_1, NULL) ;
    pthread_create(&td2, NULL, thread_handler_2, &td1) ;

    pthread_join(td1, NULL) ;
    pthread_join(td2, NULL) ;
}