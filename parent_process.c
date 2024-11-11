#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/prctl.h>

int main()
{
    prctl(PR_SET_NAME, "parent_process", 0, 0, 0) ;
    printf("Parent process Id %d\n", getpid());

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error occured\n");
    }
    else if (pid == 0)
    {
        prctl(PR_SET_NAME, "child_1", 0, 0, 0) ;
        printf("child-1 PID: %d and parent PID: %d\n", getpid(), getppid());
    }
    else{
        pid_t pid2 = fork() ;
        if(pid2 < 0){
            printf("Error occured");
        }
        else if(pid2 == 0){
            prctl(PR_SET_NAME, "child_2", 0, 0, 0) ;
            printf("child-2 PID: %d and parent PID: %d\n", getpid(), getppid());
        }
        else{
            pid_t pid3 = fork() ;
            if(pid3 < 0){
                printf("Error");
            }
            else if(pid3 == 0){
                prctl(PR_SET_NAME, "child_3", 0, 0, 0) ;
                printf("child-3 PID: %d and parent PID: %d\n", getpid(), getppid());
            }
        }
    }
    sleep(50) ;
    wait(NULL) ;
    return 0 ;
}