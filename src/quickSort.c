#include<stdlib.h>
#include<string.h>

void quickSort(void *ptr,int size,int lower,int upper,int (*func)(void *,void *),int *success, int *error){
	*success = *error = 0;
	if(lower < upper){
		int j = lower, i = j-1, p=upper;
		void *temp = (void *)malloc(size);
		if(temp == NULL){
			*error = 1;
			return;
		}
		void *a,*b,*c;
		while(j<=p){
			a = ptr + (j*size);
			b = ptr + (p*size);
			if(func(b,a)>=0){
				i++;
				c = ptr + (i*size);
				memcpy(temp,(const void *)a,size);
				memcpy(a,(const void *)c,size);
				memcpy(c,(const void *)temp,size);
			}
			j++;
		}
		quickSort((void *)ptr,size,lower,i-1,func,success,error);
		quickSort((void *)ptr,size,i+1,upper,func,success,error);
	}
}