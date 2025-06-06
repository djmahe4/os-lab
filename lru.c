#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MIN 10
int ref[MAX],count,frame[MIN],n;
void input(){
        int i,temp;
        count=0;
        printf("Enter the number of page frames");
        scanf("%d",&n);
        if(n<1||n>MIN){
                printf("\nInvalid number of frames, be between 1 and %d\n",MIN);
                return;
        }
        printf("Enter the reference string size(-1 to end):");
        scanf("%d",&temp);
        while(temp!=-1){
                ref[count++]=temp;
                if(count>=MAX){
                        printf("\nMaximum reference string size(%d) reached.\n",MAX);
                        break;
                }
                scanf("%d",&temp);
        }
        printf("\nMaximum reference string completed length %d\n",count);
}
void LRU(){
        int stack[MIN],top=0,fault=0;
        int i,k,j;
        if(n<1||count<1){
                printf("Please input the reference string and frames first:\n");
                return;
        }
        for(i=0;i<n;i++){
                stack[i]=-1;
        }
        for(i=0;i<count;i++){
                int found=0;
                for(j=0;j<top;j++){
                        if(stack[j]==ref[i]){
                                found=1;
                                break;
                        }
                }
                if(found){
                        int temp=stack[j];
                        for(k=j;k<top-1;k++){
                                stack[k]=stack[k+1];
                        }
                        stack[k]=stack[k+1];
                }
                else{
                        fault++;
                        if(top<n){
                                stack[top++]=ref[j];
                        }
                        else{
                                for(k=0;k<n-1;k++){
                                        stack[k]=stack[k+1];        
                                }
                                stack[n-1]=ref[i];
                        }
                }
                printf("\nAfter inserting %d, the stack status is:",ref[i]);
                for(j=0;j<top;j++){
                        printf("%d",stack[j]);
                }
        }
        printf("\nEnd of reference stringn insertion");
        printf("\nTotal page faults :%d",fault);
}
int main(){
        int choice;
        while(1){
                printf("\nMenu");
                printf("\n\t1.Input");
                printf("\n\t2.LRU");
                printf("\n\t0.Exit");
                printf("\n\tEnter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                        input();
                        break;
                        case 2:
                        LRU();
                        break;
                        case 0:
                        printf("\nExiting program..Goodbye!\n");
                        exit(0);
                        default:
                        printf("\nInvaild choice please enter 1,2 or 0\n");
                        break;
                }
        }
        return 0;
}
