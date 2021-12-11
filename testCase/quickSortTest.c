#include<stdio.h>
#include<stdlib.h>
#include<quickSort.h>

int compare(void *one,void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int num,i,s,e;
	printf("Enter the number of elemens\n");
	scanf("%d",&num);
	int *arr = (int *)malloc(sizeof(int)*num);
	printf("Enter the numbers\n");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	quickSort((void *)arr,sizeof(int),0,num-1,compare,&s,&e);
	printf("\nSorted array is\n");
	for(i=0;i<num;i++){
		printf("%d\n",arr[i]);
	}
	return 0;
}