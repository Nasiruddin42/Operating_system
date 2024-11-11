#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
    char *msg, buffer[100] ;
    msg = "Enter the string :" ;
    write(STDOUT_FILENO, msg, strlen(msg)+1) ;
    read(STDIN_FILENO, & buffer, sizeof(buffer)) ;
    write(STDOUT_FILENO, buffer, strlen(buffer)) ;
}