#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int var1 = 10, var2 = 5;
    printf("Parent process Id %d\n", getpid());

    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Error occured\n");
    }
    else if (pid == 0)
    {
        printf("child-1 PID: %d and parent PID: %d\n", getpid(), getppid());
        printf("addition : %d + %d = %d\n", var1, var2, var1 + var2);
    }
    else{
        pid_t pid2 = fork() ;
        if(pid2 < 0){
            printf("Error occured");
        }
        else if(pid2 == 0){
            printf("child-2 PID: %d and parent PID: %d\n", getpid(), getppid());
            printf("Subtraction : %d - %d = %d\n", var1, var2, var1 - var2);
        }
        else{
            pid_t pid3 = fork() ;
            if(pid3 < 0){
                printf("Error");
            }
            else if(pid3 == 0){
                printf("child-2 PID: %d and parent PID: %d\n", getpid(), getppid());
                printf("Multi : %d * %d = %d\n", var1, var2, var1 * var2);
            }
            printf("All child process created without grandchild\n") ;
        }
    }
    sleep(50) ;
    wait(NULL) ;
    return 0 ;
}