#ifndef stack_c 
#define stack_c 12345

#include<stdlib.h>
#include<singlyLinkedList.h>
#include<stack.h>

stack * createStack(int *success, int *e){
	*success = *e = 0;
	stack *s = (stack*)malloc(sizeof(stack));
	if(s == NULL){
		*e=1;
		return NULL;
	}
	s->count = 0;
	s->start = NULL;
	s->end = NULL;
	*success = 1;
	return s;
}

void push(stack *s,void *num,int *success, int *e){
	addToSinglyLinkedList(s,num,success,e);
}

void* pop(stack* s, int *success, int *e){
	void *num  = removeFromSinglyLinkedList(s,s->count-1,success,e);
	return num;
}

void clearStack(stack *s, int *success, int *e){
	clearSinglyLinkedList(s,success,e);
}

stack* releaseStack(stack *s, int *success, int *e){
	*success = 1;
	*e = 0;
	if(s == NULL){
		return;
	}
	if(s->start != NULL){
		clearStack(s,success,e);
	}
	free(s);
	return NULL;
}
#endif