#include<stdio.h>
void main(){
	int b,p,i,j,best;
	int bsize[10],psize[10],alloc[10];
	printf("Enter number of blocks:");
	scanf("%d",&b);
	printf("\nEnter size of blocks:");
	for(i=0;i<b;i++) scanf("%d",&bsize[i]);
	printf("Enter number of processes:");
	scanf("%d",&p);
	printf("\nEnter size of processes:");
	for(i=0;i<p;i++) {
		scanf("%d",&psize[i]);
		alloc[i]=-1;
		}
	for(i=0;i<p;i++){
		best=-1;
		for(j=0;j<b;j++){
			if(bsize[j]>=psize[i]){
				if(best==-1||bsize[j]<=bsize[best]){
					best=j;
				}
			}
		}
		if (best!=-1){
			alloc[i]=best;
			bsize[best]-=psize[i];
		}
	}
	printf("\nP no\tP size\tB no\n");
	for(i=0;i<p;i++){
		printf("%d\t%d\t",i,psize[i]);
		if (alloc[i]!=-1) printf("%d\n",alloc[i]);
		else printf("Not allocated\n");
	}
}
