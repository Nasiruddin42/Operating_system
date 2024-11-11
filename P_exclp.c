#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();

    if(pid == 0){
        execlp("/home/nasir/Documents/visual stdio/os", "os", NULL) ;
    }
    else{
        sleep(2);
        printf("complete\n") ;
    }
}