#ifndef singlyLinkedList_h
#define singlyLinkedList_h 0623

struct singlyLinkedListNode{
	void *value;
	struct singlyLinkedListNode *next;
};

struct singlyLinkedList{
	struct singlyLinkedListNode *start;
	struct singlyLinkedListNode *end;
	int count;
};

struct singlyLinkedList* createSinglyLinkedList(int *s,int *e);

void addToSinglyLinkedList(struct singlyLinkedList *list, void* data, int *s, int *e);

int getSizeOfSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e);

void* getElementFromSinglyLinkedList(struct singlyLinkedList *list, int index, int *s, int *e);

void clearSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e);

struct singlyLinkedList* releaseSinglyLinkedList(struct singlyLinkedList *list, int *s, int *e);

void insertIntoSinglyLinkedList(struct singlyLinkedList *list, int index, void *data, int *s, int * e);

void replaceInSinglyLinkedList(struct singlyLinkedList *list, int index, void* data,int *s, int *e);

void* removeFromSinglyLinkedList(struct singlyLinkedList *list, int index, int *s, int *e);

#endif