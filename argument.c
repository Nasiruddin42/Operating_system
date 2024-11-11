#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/prctl.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    printf("Num of argument : %d\n", argc) ;
    prctl(PR_SET_NAME,"parent_process", 0, 0, 0) ;
    for(int i = 2; i < argc; i++){

        pid_t pid = fork() ;
        if(pid < 0){
            printf("Error Occurred\n") ;
        }
        else if(pid == 0){
            prctl(PR_SET_NAME,argv[i], 0, 0, 0) ;
            sleep(10);
        }
    }
    wait(NULL) ;
}