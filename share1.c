#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
int main(){
        int i;
        void *shared_memory;
        char buff[100];
        int shmid;
        shmid=shmget((key_t) 2345,1024,0666|IPC_CREAT);
        printf("Key of shared memory is %d",shmid);
        shared_memory=shmat(shmid,NULL,0);
        printf("Enter some data to write to shared memory\n");
        read(0,buff,100);
        strcpy(shared_memory,buff);
        printf("You wrote: %s\n",(char*) shared_memory);
        //printf("Data read from shared memory is: %s\n",(char*) shared_memory);
}
