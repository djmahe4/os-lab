#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int fd[2];
	pid_t_child;
	char a[10]={0};
	printf("/nEnter the string to enter into the pipe:");
	scanf("%9s",a);
	if (pipe(fd)==-1){
	        perror("pipe");
	        return 1;
	}
	child=fork();
	if(child(0)){
	        perror("fork");
	        return 1;
	}
	if(child==0){
	        close(fd[0]);
	}
	if(write(fd[1],a,10)==-1){
	        perror("write");
	}
	close(fd[1]);
	}else{
	        if(read(fd[0],a,10)==-1){
	                perror("read");
	        }
	        close(fd[0]);
	        printf("\nThe string retrieved from the pipe is: %s\n",a);
	        wait(NULL);
	}
	return 0;
	}
