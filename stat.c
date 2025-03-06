#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
        char *path,path1[10];
        struct stat *nfile;
        nfile=(struct stat *)malloc(sizeof(struct stat));
        printf("Enter name of file whose statistics has to");
        scanf("%s",path1);
        stat(path1,nfile);
        printf("User id %d\n",nfile->st_uid);
        printf("Block size %d\n",nfile->st_blksize);
        printf("Last access time %d\n",nfile->st_atime);
        printf("Last modified %d\n",nfile->st_atime);
        printf("Production mode %d\n",nfile->st_mode);
        printf("Size of %d\n",nfile->st_size);
        printf("Number of lines %d\n",nfile->st_nlink);
}
