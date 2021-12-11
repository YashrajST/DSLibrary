#ifndef sort_h 
#define sort_h 432

void binaryInsertionSort(void *arr, int size, int num, int (*func)(void *,void *),int *success, int *error);

void bubbleSort(void *ptr,int num,int size,double (*func)(void *, void*), int *success, int *error);

void cocktailSort(void *arr, int size, int num, int (*func)(void *,void *),int *success, int *error);

void heapSort(void *ptr, int num, int size, int (*func)(void *,void*), int *success, int *error);

void insertionSort(void *ptr,int num,int size,int (*func)(void *, void *),int *success, int *error);

void linearSort(void *ptr,int num,int size,int (*func)(void *,void *),int *success, int *error);

void merge(void *arr,int size,int lower,int mid,int upper,int (*func)(void *,void *),int *success, int *error);

void quickSort(void *ptr,int size,int lower,int upper,int (*func)(void *,void *),int *success, int *error);

void selectionSort(void *ptr, int num, int size, int (*func)(void *, void *),int *success, int *error);

#endif