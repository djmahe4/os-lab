#include<stdio.h>
#include<unistd.h>
int main(){
        int fork(void),value;
        value=fork();
        printf("main:value=%d\n",value);
        return 0;
}
