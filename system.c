#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
static char message[]="hai hello world";
int main()
{
int fd ;
char buffer[80];
fd=open("nfile.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
if(fd!=-1)
{
printf("nfile.txt opened for read/write access\n");
write(fd,message,sizeof(message));
lseek(fd,01,0);
if(read(fd,buffer,sizeof(message)==sizeof(message)))
printf("\"%s\"was written to nfile.txt\n",buffer);
else{
printf("***Error readline nfile.txt***\n");
close(fd);
}}
else
printf("***nfile.txt already exists***\n");
exit(0);
}
