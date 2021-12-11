#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<singlyLinkedList.h>

int main(){
	int success,error;
	struct singlyLinkedList *list1 = createSinglyLinkedList(&success, &error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	int num = 10;
	addToSinglyLinkedList(list1,&num,&success,&error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	void *n = getElementFromSinglyLinkedList(list1,0, &success, &error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	clearSinglyLinkedList(list1,&success,&error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	float num1 = 50.90;
	insertIntoSinglyLinkedList(list1,0,&num1, &success, &error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	int o = 4;
	list1 = releaseSinglyLinkedList(list1, &success, &error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	replaceInSinglyLinkedList(list1,1,&o, &success, &error);
	printf("\nSuccess = %d, Error = %d\n",success,error);
	return 0;
}