#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
struct dirent*dptr;
int main(int argc,char*argv[]){
char buff[256];
DIR*dirp;
printf("\n\nEnter directory name");
scanf("%s",buff);
if((dirp=opendir(buff))==NULL)
{
printf("error");
exit(1);
}
while(dptr=readdir(dirp))
{
printf("%s\n",dptr->d_name);
}
closedir(dirp);
}
