#include<stdio.h>
#include<stdlib.h>
#include<selectionSort.h>

int compare(void *one, void *two){
	int *a,*b;
	a = (int *)one;
	b = (int *)two;
	return *a-*b;
}

int main(){
	int num, i, e, s;
	printf("Enter the number of items\n");
	scanf("%d",&num);
	int *arr = (int *)malloc(sizeof(int)*num);
	printf("Enter the numbers\n");
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	selectionSort((void *)arr,num,sizeof(int),compare,&s,&e);
	printf("Sorted array is\n");
	for(i=0;i<num;i++){
		printf("%d\n",arr[i]);
	}
	free(arr);
	return 0;
}