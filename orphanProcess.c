#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
    pid_t pid = fork() ;
    if(pid > 0){
        printf("parent pid = %d\n", getpid()) ;
    }
    else{
        if(pid == 0){  
            printf("child = %d\n", getppid()) ;
            sleep(5) ;
            printf("child = %d\n", getppid()) ;
        }
        else{
            printf("Error") ;
        }
    }
}