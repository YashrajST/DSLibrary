#include<stdio.h>
#include<stdlib.h>
#include<doublyLinkedList.h>

int main(){
	int s, e;
	struct doublyLinkedList* list1 = createDoublyLinkedList(&s,&e);
	int num = 34;
	addToDoublyLinkedList(list1,&num,&s,&e);
	int size = getSizeOfDoublyLinkedList(list1,&s,&e);
	void *ele = getElementFromDoublyLinkedList(list1,0,&s,&e);
	printf("%d  %d\n",s,e);
	return 0;
}