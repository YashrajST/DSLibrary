#include<stdio.h>
#include<stdlib.h>
#include<heapSort.h>

int compare(void *one,void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int num,i,s,e;
	printf("Enter the numer of elements to be inserted\n");
	scanf("%d",&num);
	int *arr = (int *)malloc(sizeof(int)*num);
	printf("Enter the values\n");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	heapSort((void *)arr,num,sizeof(int),compare,&s,&e);
	printf("\nSorted array is");
	for(i=0;i<num;i++){
		printf("\n%d",arr[i]);
	}
	free(arr);
	return 0;
}