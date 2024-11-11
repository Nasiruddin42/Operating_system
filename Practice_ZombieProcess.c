#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t pid = fork() ;
    if(pid < 0){
        printf("Error occured\n") ;
    }
    if(pid == 0){
        printf("child process\n") ;
    }
    else{
        sleep(10) ;
        printf("parent process\n") ;
    }

    exit(EXIT_SUCCESS ) ;
}