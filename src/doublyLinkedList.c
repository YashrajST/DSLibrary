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

dll* createDoublyLinkedList(int *success,int *error){
	*success = 0;
	*error = 0;
	dll *list = (dll*)malloc(sizeof(dll));
	if(list == NULL){
		*error = 1;
		return NULL;
	}
	list->start = NULL;
	list->end = NULL;
	list->count = 0;
	*success = 1;
	return list;
}

void addToDoublyLinkedList(dll *list, void* data, int *success, int *error){
	*success = *error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	dllnode *node = (dllnode *)malloc(sizeof(dllnode));
	if(node == NULL){
		*error = 1;
		return;
	}
	node->value = data;
	node->next = NULL;
	if(list->start == NULL){
		list->start = node;
		list->end = node;
		node->prev = NULL;
		list->count++;
	}else{
		list->end->next = node;
		node->prev = list->end;
		list->end = node;
		list->count++;
	}
	*success = 1;
}

int getSizeOfDoublyLinkedList(dll *list,int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return -1;
	}
	*success = 1;
	return list->count;
}

void* getElementFromDoublyLinkedList(dll *list, int index, int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	if(list->start == NULL){
		*error = 3;
		return;
	}
	if(index >= list->count){
		*error = 4;
		return;
	}
	if(index = list->count-1){
		*success = 1;
		return list->end->value;
	}
	int num=0;
	dllnode *t;
	t = list->start;
	while(num != index){
		t = t->next;
		num++;
	}
	*success = 1;
	return t->value;
}

void clearDoublyLinkedList(dll *list, int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	while(list->start != NULL){
		dllnode *temp;
		temp = list->end;
		if(temp->prev == NULL){
			list->start = NULL;
			list->end = NULL;
			list->count--;
			free(temp);
			*success = 1;
			return;
		}
		temp = temp->prev;
		free(temp->next);
		list->end = temp;
		temp->next = NULL;
		list->count--;
	}
	*success = 1;
}

dll* releaseDoublyLinkedList(dll *list, int *success, int *error){
	*success = 1;
	*error = 0;
	if(list == NULL){ 
		return NULL;
	}
	if(list->end != NULL){
		clearDoublyLinkedList(list, success, error);
	}
	free(list);
	return NULL;
}

void insertIntoDoublyLinkedList(dll *list, int index, void *data, int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	if(list->start == NULL && index > 0){
		*error = 4;
		return;
	}
	if(index > list->count){
		*error = 4;
		return;
	}
	dllnode *ins = (dllnode*)malloc(sizeof(dllnode));
	if(ins == NULL){
		*error = 1;
		return;
	}
	ins->value = data;
	if(index == 0){
		ins->next = list->start;
		if(list->start == NULL){
			list->end = ins;	
		}
		list->start = ins;
		ins->prev = NULL;
		list->count++;
		*success = 1;
		return;
	}
	int n = 0;
	dllnode *temp;
	if(index = list->count){
		list->end->next = ins;
		ins->next = NULL;
		ins->prev = list->end;
		list->end = ins;
		list->count++;
		*success = 1;
		return;
	}
	temp = list->start;
	while(n != index-1){
		temp = temp->next;
		n++;
	}
	ins->next = temp->next;
	temp->next->next->prev = ins;
	temp->next = ins;
	ins->prev = temp;
	list->count++;
	*success = 1;
}

void replaceInDoublyLinkedList(dll *list, int index, void* data, int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	if(list->start == NULL || index > list->count){
		*error = 4;
		return;
	}
	int n = 0;
	dllnode *temp;
	temp = list->start;
	while(n != index){
		temp = temp->next;
		n++;
	}
	free(temp->value);
	temp->value = data;
	*success = 1;
}

void* removeFromDoublyLinkedList(dll *list, int index, int *success, int *error){
	*success = 0;
	*error = 0;
	if(list == NULL){
		*error = 2;
		return;
	}
	if(list->start == NULL){
		*error = 2;
		return;
	}
	if(index >= list->count) {
		*error = 4;
		return; 
	}
	dllnode *temp = list->start;
	int n=0;
	void *num;
	if(index == 0){
		if(list->start == list->end){
			list->start = NULL;
			list->end = NULL;
			num = temp->value;
			free(temp);
			list->count--;
			*success = 1;
			return num;
		}
		list->start = temp->next;
		num = temp->value;
		free(temp);
		list->start->prev = NULL;
		list->count--;
		*success = 1;
		return num;
	}
	if(index == list->count-1){
		temp = list->end;
		list->end = temp->prev;
		temp->prev->next = NULL;
		list->count--;
		num = temp->value;
		free(temp);
		*success = 1;
		return num;
	}
	while(n != index-1){
		temp = temp->next;
		n++;
	}
	dllnode *t;
	t = temp->next;
	temp->next = t->next;
	t->next->prev = t->prev;
	num = t->value;
	free(t);
	list->count--;
	*success = 1;
	return num;
}