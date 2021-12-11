#include<stdio.h>
#include<stdlib.h>
#include<insertionSort.h>

int compare(void *one,void *two){
	int *x,*y;
	x = (int *)one;
	y = (int *)two;
	return *x-*y;
}

int main(){
	int i,num,s,e;
	int *arr,*a;
	printf("Enter the number of inputs\n");
	scanf("%d",&num);
	arr = (int *)malloc(sizeof(int)*num);
	if(arr == NULL){
		printf("cannot allocate memory\n");
		return 0;
	}
	printf("enter the numbers\n");
	for(i=0;i<num;i++){
		scanf("%d", &arr[i]);
	}
	insertionSort((void *)arr,num,sizeof(int),compare,&s,&e);
	printf("\nSorted array is");
	for(i=0;i<num;i++){
		printf("\n%d",arr[i]);	
	}
	free(arr);
	return 0;
}