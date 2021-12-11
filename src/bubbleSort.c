#include<stdlib.h>
#include<string.h>

void bubbleSort(void *ptr,int num,int size,double (*func)(void *, void*), int *success, int *error){
	*success = *error = 0;
	int i,j;
	void *a,*b,*c;
	c = (void *)malloc(size);
	if(c == NULL){
		*error = 1;
		return;
	}
	for(i=0;i<num;i++){
		for(j=0;j<num-i-1;j++){
			a = ptr + (j*size);
			b = ptr + ((j+1)*size);
			if(func((void *)a,(void *)b)>0){
				memcpy(c,(const void *)a,size);
				memcpy(a,(const void *)b,size);
				memcpy(b,(const void *)c,size);
			}
		}
	}
	free(c);
	*success = 1;
}