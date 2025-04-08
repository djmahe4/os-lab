#include<stdio.h>
void main(){
	int work[10],avail[10],max[10][10],alloc[10][10],need[10][10];
	int i,j,k,n,m,count,fcount=0,pr[10];
	char finish[10];
	printf("Enter the number of processes:");
	scanf("%d",&n);
	printf("\nEnter the number of resources:");
	scanf("%d",&m);
	printf("\nEnter available number of resources:");
	for(i=0;i<m;i++) {
		scanf("%d",&avail[i]);
		work[i]=avail[i];
		}
	printf("\nEnter max alloccation matrix:");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter allocation matrix:");
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	for(i=0;i<n;i++) finish[i]='f';
	//safety algorithm
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			if(finish[i]=='f'){
				count=0;
			}
			for(j=0;j<m;j++){
				if(need[i][j]<=work[j]){
					count++;
					if(count==m){
						for(j=0;j<m;j++){
							work[j]+=alloc[i][j];
						}
						finish[i]='t';
						pr[fcount++]=i;
					}
				}
			}
		}
	}
	if(fcount==n){
		printf("\nSafe state\nSequence is :");
		for(i=0;i<n;i++) printf("\tp%d",pr[i]);
	}
	else printf("\nNot a safe state");
}
