#include<stdlib.h>
#include<string.h>

void binaryInsertionSort(void *arr, int size, int num, int (*func)(void *,void *),int *success, int *error){
	*success = *error = 0;
	int i=1,j,lower,upper,mid;
	void *temp,*a,*b;
	temp = (void *)malloc(size);
	if(temp == NULL){
		*error = 1;
		return;
	}
	while(i<num){
		j=i;
		lower = 0;
		upper = i-1;
		memcpy(temp,(const void *)(arr + (i*size)),size);
		while(lower<=upper){
			mid = (lower + upper)/2;
			a = arr + (mid * size);
			if(func((void *)temp,(void *)a) == 0){
				break;
			}
			if(func((void *)temp,(void *)a)>0){
				lower = mid + 1;
			}else{
				upper = mid - 1;
			}
		}
		while(j>upper){
			memcpy((arr+(j*size)),(const void *)(arr+((j-1)*size)),size);
			j--;
		}
		memcpy(arr+((upper+1)*size),(const void *)temp,size);
		i++;
	}
	*success = 1;
	free(temp);
}