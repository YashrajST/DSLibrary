#include<stdio.h>
#include<stdlib.h>
#include<bubbleSort.h>

double compare(void *one, void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int *arr;
	int i,num,s,e;
	printf("Enter number of inputs\n");
	scanf("%d",&num);
	arr = (int *)malloc(sizeof(int)*num);
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort((void *)arr,num,sizeof(int),compare,&s,&e);
	printf("\nThe sorted array is");
	for(i= 0;i<num;i++){
		printf("\n%d", arr[i]);
	}
	free(arr);
	return 0;
}