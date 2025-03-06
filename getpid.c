#include<stdio.h>
#include<unistd.h>
int main(){
        int pid;
        pid=getpid();
        printf("Process ID is %d\n",pid);
        pid=getppid();
        printf("Parent process ID is %d\n",pid);
}
