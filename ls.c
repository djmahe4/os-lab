#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#define PATH_MAX 4096
int main(int argc,char**argv)
{
DIR*dir;
struct dirent*dirent;
char* where=NULL;
if(argc==1)
{
char cwd[PATH_MAX];
if(getcwd(cwd,sizeof(cwd))==NULL)
{
fprintf(stderr,"error getting current directory:%s\n",strerror(errno));
return 1;}
where = cwd;
}
else{
where = argv[1];
}
if(NULL==(dir=opendir(where))){
        fprintf(stderr,"%d(%s) opendir %s failed\n",errno,strerror(errno),where);
        return 2;
        }
        while(NULL!=(dirent=readdir(dir))){
                printf("%s\n",dirent->d_name);
        }
        closedir(dir);
        return 0;
}
