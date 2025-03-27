#include<stdio.h>
void main(){
        int i,j,n,block[20],start;
        printf("Enter the number of files:\n");
        scanf("%d",&n);
        printf("Enter the number of blocks needed for each file:\n");
        for(i=0;i<n;i++){
          scanf("%d",&block[i]);
        }
        start=0;
        printf("\t\tFilename\tStart\tSize of file\t\t\n");
        printf("\n\t\tFile\t\t%d\t\t%d\t\t\n",start,block[0]);
        for(i=2;i<=n;i++){
          start=start+block[i-2];
          printf("\t\tFile %d\t\t%d\t\t%d\n",i,start,block[i-1]);
        }
}
