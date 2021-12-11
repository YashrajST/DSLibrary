#ifndef sort_c 
#define sort_c 4236

#include<stdlib.h>
#include<string.h>
#include<sort.h>
#include<utility.h>

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

void heapSort(void *ptr, int num, int size, int (*func)(void *,void*), int *success, int *error){
	*success = *error = 0;
	if(num > 0){
		int i=0,lci,rci,pi;
		void *temp,*leftc,*rightc,*parent;
		temp = (void *)malloc(size);
		if(temp == NULL){
			*error = 1;
			return;
		}
		while(i<num){
			pi=i;
			lci = (2*i)+1;
			rci = (2*i)+2;
			parent = ptr + (pi*size);
			leftc = ptr + (lci*size);
			rightc = ptr + (rci*size);
			if(lci < num && func((void *)leftc,(void *)parent) > 0){
				memcpy(temp,(const void *)leftc,size);
				memcpy(leftc,(const void *)parent,size);
				memcpy(parent,(const void *)temp,size);
				i = (i-1)/2;
				continue;
			}
			if(rci < num && func((void *)rightc,(void *)parent) > 0){
				memcpy(temp,(const void *)rightc,size);
				memcpy(rightc,(const void *)parent,size);
				memcpy(parent,(const void *)temp,size);
				i = (i-1)/2;
				continue;
			}
			if(lci >= num || rci >= num){
				break;
			}
			i++;
		}
		memcpy(temp,(const void *)(ptr),size);
		memcpy(ptr,(const void *)(ptr+((num-1)*size)),size);
		memcpy((ptr+((num-1)*size)),(const void *)temp,size);
		heapSort((void *)ptr,num-1,size,func,success,error);
	}
	*success = 1;
}



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

void mergeSort(void *arr, int size, int lower, int upper,int (*func)(void *,void *),int *success, int *error){
	if(lower<upper){
		int mid = (lower+upper)/2;
		
		mergeSort((void *)arr, size,lower,mid,func,success,error);
		mergeSort((void *)arr, size,mid+1,upper,func,success,error);
		
		merge((void *)arr,size,lower,mid,upper,func,success,error);
	}
}

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

#endif