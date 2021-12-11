#include<stdlib.h>
#include<string.h>

void linearSort(void *ptr,int num,int size,int (*func)(void *,void *),int *success, int *error){
	*success = *error = 0;
	int i,j;
	void *x,*y,*temp;
	temp = (void *)malloc(size);
	if(temp == NULL){
		*error = 1;
		return;
	}
	for(i=0;i<num-1;i++){
		x = ptr + (i*size);
		
		for(j=i+1;j<num;j++){
			y = ptr + (j*size);
			if(func(x,y)>0){
				memcpy(temp,(const void *)x,size);
				memcpy(x,(const void *)y,size);
				memcpy(y,(const void *)temp,size);
			}
		}
	}
	free(temp);
	*success = 1;
}