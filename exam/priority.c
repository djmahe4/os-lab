#include<stdio.h>
void main(){
	int n;
	printf("Enter number of processes:");
	scanf("%d",&n);
	int process[n],tat[n],bt[n],wt[n],priority[n],i,j,ttat=0,twt=0;
	printf("\nEnter burst time and priority of processes:");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		scanf("%d",&priority[i]);
		process[i]=i+1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;i++){
			if(priority[i]>priority[j]){
				int temp=priority[i];
				priority[i]=priority[j];
				priority[j]=temp;
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				temp=process[i];
				priority[i]=process[j];
				process[j]=temp;
				
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=bt[i-1]+wt[i-1];
	}
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
	printf("\nProcess ID\tPriority\tbt\twt\ttat\n");
	for(i=0;i<n;i++){
		printf("\np%d\t%d\t%d\t%d\t%d\n",process[i],priority[i],bt[i],wt[i],tat[i]);
		ttat+=tat[i];
		twt+=wt[i];
	}
	printf("\nAvg TAT: %.2f",(float) ttat/n);
	printf("\nAvg WT: %.2f",(float) twt/n);
}
