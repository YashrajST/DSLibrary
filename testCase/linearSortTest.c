#include<linearSort.h>
#include<stdio.h>
#include<stdlib.h>

int compare(void *one, void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int num =10,i,s,e;
/*
	int *arr;
	printf("Enter the number of elements\n");
	scanf("%d",&num);
	arr = (int *)malloc(sizeof(int)*num);
	if(arr == NULL){
		printf("Cannot allocate memory");
		return 0;
	}
	for(i=0;i<num;i++){
		scanf("%d", &arr[i]);
	}
*/
	int arr[] = {2,56,23,76,8,34,1,90,43,55};
	linearSort((void *)arr,num,sizeof(int),compare,&s,&e);
	printf("Sorted array is - \n");
	for(i=0;i<num;i++){
		printf("%d\n",arr[i]);
	}
//	free(arr);
	return 0;
}