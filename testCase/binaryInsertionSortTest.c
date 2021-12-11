#include<stdio.h>
#include<stdlib.h>
#include<binaryInsertionSort.h>

int compare(void *one,void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}


int main(){
	int num, i;
	int s,e;
	printf("Enter the number of elements\n");
	scanf("%d",&num);
	int *arr = (int *)malloc(sizeof(int)*num);
	printf("Enter the elements\n");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	binaryInsertionSort((void *)arr,sizeof(int),num,compare,&s,&e);
	printf("\nSuccess = %d, Error = %d\n",s,e);
	printf("\nThe sorted array is");
	for(i=0;i<num;i++){
		printf("\n%d",arr[i]);
	}
	return 0;
}