#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int fd[2];
pid_t child;
char a[10]={0};
printf("\n enter the string to enter into the pipe:");
scanf("%9s",a);
if(pipe(fd)==-1)
{
perror("pipe");
return 1;
}
child=fork();
if(child<0)
{
perror("fork");
return 1;
}
if(child==0)
{
close(fd[0]);
if(write(fd[1],a,10)==-1)
{
perror("write");
}
close(fd[1]);
}
else
{
close(fd[1]);
if(read(fd[0],a,10)==1)
{
perror("read");
}
close(fd[0]);
printf("\nthe string retrieved from the pipe is:%s\n",a);
wait(NULL);
}
return 0;
}

