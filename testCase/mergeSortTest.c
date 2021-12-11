#include<stdio.h>
#include<stdlib.h>
#include<mergeSort.h>

int compare(void *one, void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int num,i,s,e;
	printf("Enter the number of elements\n");
	scanf("%d",&num);
	int *arr = (int *)malloc(sizeof(int)*num);
	printf("Enter the elements\n");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	mergeSort((void *)arr,sizeof(int),0,num-1,compare,&s,&e);
	printf("\nThe sorted array is ");
	for(i=0;i<num;i++){
		printf("\n%d",arr[i]);
	}
	free(arr);
	return 0;
}