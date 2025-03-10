#include<stdio.h>
#include<stdlib.h>
int n=0,buffersize=0,currentsize=0;
void producer(){
        printf("\nEnter number of elements to be produced:");
        scanf("%d",&n);
        if(0<=(buffersize-(currentsize+n))){
                currentsize+=n;
                printf("%d elements produced current buffersize: %d (max buffer size: %d)\n",n,currentsize,buffersize);
        }
        else{
                printf("\nBuffer overflow! cannot produce %d elements\n",n);
        }
}
void consumer(){
        int x;
        printf("\nEnter number of elements to be consumed:");
        scanf("%d",&x);
        if(currentsize>=x){
                currentsize-=x;
                printf("\n%d elements consumed Current buffersize: %d\n",x,currentsize);
        }
        else{
                printf("\nError: Cannot consume more elements that are available Current size:%d\n",currentsize);
        }
}
int main(){
        int c;
        printf("\nEnter maximum size buffer:");
        scanf("%d",&buffersize);
        do{
                printf("\n1.Producer 2.Consumer 3.Exit");
                printf("\nEnter choice:");
                scanf("%d",&c);
                switch(c){
                        case 1:
                        if(currentsize>=buffersize){
                                printf("\nBuffer is full. Cannot produce\n");
                        }
                        else{
                                producer();
                        }
                        break;
                        case 2:
                        if(currentsize<=0){
                                printf("\nBuffer is empty.Cannot consume\n");
                        }
                        else{
                                consumer();
                        }
                        break;
                        case 3:
                        printf("\nExiting program.Goodbye!\n");
                        break;
                        default:
                        printf("\nInvalid choice.Please enter 1,2 or 3\n");
                        break;
                }
        }
        while(c!=3);
        return 0;
        
}
