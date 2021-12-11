#include<stdlib.h>
#include<string.h>

void merge(void *arr,int size,int lower,int mid,int upper,int (*func)(void *,void *),int *success, int *error){
	*success = *error = 0;
	int i, j, k=0, n, m;
	n = mid - lower + 1;
	m = upper-mid;
	void *a,*b;
	void *a1 = (void *)malloc(size*n);
	void *a2 = (void *)malloc(size*m);
	if(a1 == NULL || a2 == NULL){
		*error = 1;
		return;
	}
	for(i=lower;i<=mid;i++){
		memcpy((a1+(k*size)),(const void *)(arr+(i*size)),size);
		k++;
	}
	k=0;
	for(i=mid+1;i<=upper;i++){
		memcpy((a2+(k*size)),(const void *)(arr+(i*size)),size);
		k++;
	}
	//merging
	k=lower;
	i = 0;
	j = 0;
	while(i<n && j<m){
		a = a1 + (i * size);
		b = a2 + (j * size);
		if(func((void *)b,(void *)a)>0){
			memcpy((arr+(k*size)),(const void *)a,size);
			k++;
			i++;
		}else{
			memcpy((arr+(k*size)),(const void *)b,size);
			k++;
			j++;
		}
	}
	while(i<n){
		a = a1 + (i * size);
		memcpy((arr+(k*size)),(const void *)a,size);
		i++;
		k++;
	}
	while(j<m){
		b = a2 + (j * size);
		memcpy((arr+(k*size)),(const void *)b,size);
		j++;
		k++;
	}
	free(a1);
	free(a2);
	*success = 1;
}

void mergeSort(void *arr, int size, int lower, int upper,int (*func)(void *,void *),int *success, int *error){
	if(lower<upper){
		int mid = (lower+upper)/2;
		
		mergeSort((void *)arr, size,lower,mid,func,success,error);
		mergeSort((void *)arr, size,mid+1,upper,func,success,error);
		
		merge((void *)arr,size,lower,mid,upper,func,success,error);
	}
}