#include<string.h>
#include<stdlib.h>

int compare(void *one,void *two);

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
		heapSort((void *)ptr,num-1,size,compare,success,error);
	}
	*success = 1;
}