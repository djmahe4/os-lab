#include<stdio.h>
int main(){
        int num_blocks,num_processes;
        printf("Enter the number of memory blocks:");
        scanf("%d",&num_blocks);
        int block_sizes[num_blocks];
        printf("Enter the sizes of the %d memory blocks:\n",num_blocks);
        for(int i=0;i<num_blocks;i++){
                printf("Block %d size:",i+1);
                scanf("%d",&block_sizes[i]);
        }
        printf("\nEnter the number of processes:");
        scanf("%d",&num_processes);
        int process_sizes[num_processes];
        printf("Enter the size of the %d processes:\n",num_processes);
        for(int i=0;i<num_processes;i++){
                printf("Process %d size:",i+1);
                scanf("%d",&process_sizes[i]);
        }
        int allocation[num_processes];
        for(int i=0;i<num_processes;i++){
                allocation[i]=-1;
        }
        for(int i=0;i<num_processes;i++){
                int max_index=-1;
                for(int j=0;j<num_blocks;j++){
                        if(block_sizes[j]>=process_sizes[i]){
                                if(max_index==-1||block_sizes[j]>block_sizes[max_index]){
                                        max_index=j;
                                }
                        }
                }
                if(max_index!=-1){
                        allocation[i]=max_index;
                        block_sizes[max_index]-=process_sizes[i];
                }
        }
        printf("\nProcess no\tprocess size\tblock size\n");
        for(int i=0;i<num_processes;i++){
                printf("%d\t\t%d\t\t",i+1,process_sizes[i]);
                if(allocation[i]!=-1){
                        printf("%d\n",allocation[i]+1);
                }
                else{
                        printf("Not allocated\n");
                }
        }
        return 0;
}
