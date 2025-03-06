#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
int p[30],bt[30],tot_tat=0,wt[30],n,tot_wt=0,tat[30],FCFS_wt=0,FCFS_tat=0;
float awt,avg_tat,avg,avg_wt;
int WT_TAT(int *a,int *b,int n){
        int i,j;
        for(i=0;i<n;i++){
                if(i==0){
                        tat[i]=bt[i];
                        
                }
               
                else{
                        tat[i]=tat[i-1]+bt[i];
                        tot_tat=tot_tat+tat[i];
                }
                
                //printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],tat[i],wt[i]);
                
        }
        *a=tot_tat;
                wt[0]=0;
                for(i=1;i<n;i++){
                        wt[i]=wt[i-1]+bt[i-1];
                        tot_wt=tot_wt+wt[i];
                }
        *b=tot_wt;
        return 0;
                
}
void main(){
        int i,j;
        printf("\nFCFS Algorithm\n");
        printf("\nEnter the no of processes\n");
        scanf("%d",&n);
        printf("Enter burst time for each process\n");
        for(i=0;i<n;i++){
                scanf("%d",&bt[i]);
                p[i]=i;
        }
        WT_TAT(&FCFS_tat,&FCFS_wt,n);
        printf("\nProcess\tBT\tTAT\tWT\n");
        for(i=0;i<n;i++){
                
                printf("Process[%d]\t%d\t%d\t%d\t\n",i+1,bt[i],tat[i],wt[i]);
        }
        printf("\nTotal TAT: %d",tot_tat);
        printf("\nAvg TAT: %d",tot_tat/n);
        printf("\nTotal WT: %d",tot_wt);
        printf("\nAvg WT: %d",tot_wt/n);
}
