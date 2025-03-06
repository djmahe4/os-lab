#include<stdio.h>
int p[30],bt[30],tot_tat=0,pr[30],wt[30],tot_wt=0,tat[30],PR_wt=0,PR_tat=0,n;
int WT_TAT(int *a,int *b);
int sort();
void swap(int *a,int *b);
void main(){
        int i   ;
        printf("Enter no of process\n");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                printf("Enter burst time & priority process [%d]:",i+1);
                scanf("%d%d",&bt[i],&pr[i]);
                p[i]=i;
        }
        sort();
        WT_TAT(&PR_tat,&PR_wt);
        printf("Total TAT: %d",PR_tat);
        printf("Avg TAT: %2f",(float) PR_tat/n);
        printf("Total WT: %d",PR_wt);
        printf("Avg WT: %2f",(float) PR_wt/n);
        
}
int WT_TAT(int *a,int *b){
        int i;
        for(i=0;i<n;i++){
        if(i==0){
                tat[i]=bt[i];
          }
        else
                tat[i]=tat[i-1]+bt[i];
        
        tot_tat+=tat[i];
        }
        *a=tot_tat;
        wt[0]=0;
        for(i=1;i<n;i++){
                wt[i]=wt[i-1]+bt[i-1];
                tot_wt+=wt[i];
        }
        *b=tot_wt;
        printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tTURNAROUNDTIME\t\tWAITINGTIME");
        for(i=0;i<n;i++){
                printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i]+1,bt[i],pr[i],tat[i],wt[i]);
        }
}
int sort(){
        int i,j;
        for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                        if(pr[i]>pr[j]){
                                swap(&bt[i],&bt[j]);
                                swap(&p[i],&p[j]);
                                swap(&pr[i],&pr[j]);
                        }
                }
        }
        return 0;
}

void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
}

