#ifndef singlyLinkedList_c
#define singlyLinkedList_c 1234

#include<stdlib.h>
#include<string.h>
#include<singlyLinkedList.h>

struct singlyLinkedList* createSinglyLinkedList(int *s,int *e){
	*s = 0;
	*e = 0;
	struct singlyLinkedList *list = (struct singlyLinkedList *)malloc(sizeof(struct singlyLinkedList));
	if(list == NULL){
		*e = 1;
		return NULL;
	}
	list->start = NULL;
	list->end = NULL;
	list->count = 0;
	*s = 1;
	return list;
}

void addToSinglyLinkedList(struct singlyLinkedList *list, void* data, int *s, int *e){
	*s = 0;
	*e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	struct singlyLinkedListNode *node1 = (struct singlyLinkedListNode *)malloc(sizeof(struct singlyLinkedListNode));
	if(node1 == NULL){
		*e = 1;
		return;
	}
	node1->value = data;
	node1->next = NULL;
	if(list->start == NULL){
		list->start = node1;
		list->end = node1;
		list->count++;
	}else{
		list->end->next = node1;
		list->end = node1;
		list->count++;
	}
	*s = 1;
}

int getSizeOfSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return -1;
	}
	*s = 1;
	return list->count;
}

void* getElementFromSinglyLinkedList(struct singlyLinkedList *list, int index, int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	if(index >= list->count){
		*e = 4;
		return NULL;
	}
	int num=0;
	struct singlyLinkedListNode *t;
	t = list->start;
	while(num != index){
		t = t->next;
		num++;
	}
	*s = 1;
	return t->value;
}

void clearSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	struct singlyLinkedListNode *temp;
	if(list->start == NULL){
		*s = 1;
		return;
	}
	while(list->start != NULL){
		temp = list->start;
		if(temp->next == NULL){
			free(temp);
			list->end = NULL;
			list->start = NULL;
			list->count--;
			*s = 1;
			return;
		}
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		list->end = temp;
		list->count--;
	}
	*s = 1;
}

struct singlyLinkedList* releaseSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*s = 1;
		return NULL;
	}
	if(list->end != NULL){
		clearSinglyLinkedList(list, s, e);
	}
	free(list);
	*s = 1;
	return NULL;
}

void insertIntoSinglyLinkedList(struct singlyLinkedList *list, int index, void *data, int *s, int * e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	if(list->start == NULL && index > 0){
		*e = 4;
		return;
	}
	if(index > list->count){
		*e = 4;
		return;
	}
	struct singlyLinkedListNode *ins = (struct singlyLinkedListNode*)malloc(sizeof(struct singlyLinkedListNode));
	if(ins == NULL){
		*e = 1;
		return;
	}
	ins->value = data;
	if(index == 0){
		ins->next = list->start;
		list->start = ins;
		list->count++;
		*s = 1;
		return;
	}
	int n = 0;
	struct singlyLinkedListNode *temp;
	temp = list->start;
	while(n != index-1){
		temp = temp->next;
		n++;
	}
	ins->next = temp->next;
	temp->next = ins;
	list->count++;
	if(index == list->count){
		list->end = ins;
	}
	*s = 1;
}

void replaceInSinglyLinkedList(struct singlyLinkedList *list, int index, void* data,int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	if(list->start == NULL || index > list->count){
		*e = 4;
		return;
	}
	int n = 0;
	struct singlyLinkedListNode *temp;
	temp = list->start;
	while(n != index){
		temp = temp->next;
		n++;
	}
	temp->value = data;
	*s = 1;
}

void* removeFromSinglyLinkedList(struct singlyLinkedList *list, int index, int *s, int *e){
	*s = *e = 0;
	if(list == NULL){
		*e = 2;
		return;
	}
	if(list->start == NULL || index > list->count){
		*e = 4;
		return;
	}
	int n=0;
	void *num;
	struct singlyLinkedListNode* temp;
	temp = list->start;
	if(index == 0){
		num = temp->value;
		if(temp->next == NULL){
			list->start = NULL;
			list->end = NULL;
		}else{
			list->start = temp->next;
		}
		list->count--;
		free(temp);
		*s = 1;
		return num;
	}
	while(n != index-1){
		temp= temp->next;
		n++;
	}
	num = temp->next->value;
	if(temp->next->next == NULL){
		list->end = temp;
		temp->next = NULL;
		list->count--;
		free(temp->next);
		*s = 1;
		return num;
	}
	struct singlyLinkedListNode* t;
	t = temp->next;
	temp->next = t->next;
	list->count--;
	free(t);
	*s = 1;
	return num;
}
#endif