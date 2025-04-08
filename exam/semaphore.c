#include<stdio.h>
#include<stdlib.h>
int mutex=1,x=0,empty=3,full=0;
int wait(int s){
	return --s;
}
int signal(int s){
	return ++s;
}
void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	printf("\nProducer produced the item %d",++x);
	mutex=signal(mutex);
}
void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumed the item %d",x--);
	mutex=signal(mutex);
}
void main(){
	int n;
	while(1){
		printf("\nMENU:\n\t1.Producer\n\t2.Consumer\n\t3.Exit\nEnter choice:");
		scanf("%d",&n);
		switch(n){
			case 1:
			if((mutex==1)&&(empty!=0)) producer();
			else printf("\nBuffer is full");
			break;
			case 2:
			if((mutex==1)&&(full!=0)) consumer();
			else printf("\nBuffer is empty");
			break;
			case 3:
			exit(0);
			default:
			printf("\nInvalid choice..");
			break;
		}
	}
}
