#include<string.h>
#include<stdlib.h>

void insertionSort(void *ptr,int num,int size,int (*func)(void *, void *),int *success, int *error){
	*success = *error = 0;
	int i,j;
	void *temp,*a,*b;
	temp = (void *)malloc(size);
	if(temp == NULL){
		*error = 1;
		return;
	}
	for(i=1;i<num;i++){
		j= i-1;
		memcpy(temp,(const void *)(ptr+(i*size)),size);
		while(j>=0){
			a = ptr + (j*size);
			if(func(a,temp)>0){
				b = ptr + ((j+1)*size);
				memcpy(b,(const void *)a,size);
			}else break;
			j--;
		}
		b = ptr + ((j+1)*size);
		memcpy(b,(const void *)temp,size);
	}
	free(temp);
	*success = 1;
}