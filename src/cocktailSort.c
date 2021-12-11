#include<string.h>
#include<stdlib.h>

void cocktailSort(void *arr, int size, int num, int (*func)(void *,void *),int *success, int *error){
	*success = *error = 0;
	int i, j=0, swap=1;
	void *temp,*a,*b;
	temp = (void *)malloc(size);
	if(temp == NULL){
		*error = 1;
		return;
	}
	while(swap){
		swap = 0;
		for(i=j;i<num-1-j;i++){
			a = arr + (i*size);
			b = arr + ((i+1)*size);
			if(func(a,b)>0){
				memcpy(temp,(const void *)b,size);
				memcpy(b,(const void *)a,size);
				memcpy(a,(const void *)temp,size);
				swap = 1;
			}
		}
		if(swap == 0) break;
		swap = 0;
		i--;
		while(i>j){
			a = arr + (i*size);
			b = arr + ((i-1)*size);
			if(func(b,a)>0){
				memcpy(temp,(const void *)b,size);
				memcpy(b,(const void *)a,size);
				memcpy(a,(const void *)temp,size);
				swap = 1;
			}
			i--;
		}
		j++;
	}
	free(temp);
	*success = 1;
}
