#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
        int pid;
        char *args[]={"/bin/ls","-l",0};
        printf("\nParent process");
        pid=fork();
        if(pid==0){
                execv("/bin/ls",args);
                printf("\nChild process");
                wait(0);
        }
        else{
                printf("Parent process");
                exit(0);
        }
        
}
