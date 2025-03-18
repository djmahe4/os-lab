#include<stdio.h>
struct process{
        int ps;
        int flag;
}p[50];
struct sizes{
        int size;
        int alloc;
}s[5];
int main(){
        int i=0,np=0,n=0,j=0;
        printf("\nFirst fit memory allocation\n");
        printf("\nEnter the number of block:");
        scanf("%d",&n);
        printf("\nEnter the size for %d blocks",n);
        for(i=0;i<n;i++){
                printf("\nEnter the size for block %d:",i);
                scanf("%d",&s[i].size);
                s[i].alloc=0;
        }
        printf("\nEnter the number of processes:");
        scanf("%d",&np);
        printf("Enter the size for %d processes\n",np);
        for(i=0;i<np;i++){
                printf("Enter the size of process %d",i);
                scanf("%d",&p[i].ps);
                p[i].flag=0;
        }
        printf("\nAllocation of blocks using First fit is as follows:\n");
        printf("\nProcess\tProcess Size\tBlock Size\n");
        for(i=0;i<np;i++){
                for(j=0;j<n;j++){
                        if(p[i].flag!=1){
                                if(p[i].ps<=s[j].size && s[j].alloc==0){
                                        p[i].flag=1;
                                        s[j].alloc=1;
                                        printf("P%d\t\t%d\t\t%d\n",i,p[i].ps,s[j].size);
                                        break;
                                }
                        }
                }
        }
        for(i=0;i<np;i++){
                if(p[i].flag!=1){
                        printf("Process %d must wait as there is no sufficient memory\n",i);
                }
        }
        return 0;
}
