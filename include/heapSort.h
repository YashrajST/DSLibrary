#ifndef HEAPS_0623_
#define HEAPS_0623_

int compare(void *one,void *two);

void heapSort(void *ptr, int num, int size, int (*func)(void *,void*), int *success, int *error);

#endif