#include<string.h>
#include<stdlib.h>

void selectionSort(void *ptr, int num, int size, int (*func)(void *, void *),int *success, int *error){
	*success = *error = 0;
	int i,j,k;
	void *temp,*a,*b;
	temp = (void *)malloc(size);
	if(temp == NULL){
		*error = 1;
		return;
	}
	for(i=0;i<num-1;i++){
		memcpy(temp,(const void *)(ptr + (i*size)),size);
		k=i;
		for(j=i;j<num;j++){
			a = ptr + (j*size);
			if(func((void *)temp,(void *)a)>0){
				k=j;
				memcpy(temp,(const void *)a,size);
			}
		}
		memcpy(ptr+(k*size),(const void *)(ptr+(i*size)),size);
		memcpy((ptr+(i*size)),(const void *)temp,size);
	}
	free(temp);
	*success = 1;
}