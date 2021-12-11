#ifndef DOUBLYLINKED_0623_
#define DOUBLYLINKED_0623_
#include<stdlib.h>

typedef struct doublyLinkedListNode{
	void *value;
	struct doublyLinkedListNode *prev;
	struct doublyLinkedListNode *next;
}dllnode;

typedef struct doublyLinkedList{
	dllnode *start;
	dllnode *end;
	int count;
}dll;

dll* createDoublyLinkedList(int *success,int *error);

void addToDoublyLinkedList(dll *list, void* data, int *success, int *error);

int getSizeOfDoublyLinkedList(dll *list,int *success, int *error);

void* getElementFromDoublyLinkedList(dll *list, int index, int *success, int *error);

void clearDoublyLinkedList(dll *list, int *success, int *error);

dll* releaseDoublyLinkedList(dll *list, int *success, int *error);

void insertIntoDoublyLinkedList(dll *list, int index, void *data, int *success, int *error);

void replaceInDoublyLinkedList(dll *list, int index, void* data, int *success, int *error);

void* removeFromDoublyLinkedList(dll *list, int index, int *success, int *error);

#endif
