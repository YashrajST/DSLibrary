#ifndef stack_h
#define stack_h 0623

typedef struct stackNode{
	void *value;
	struct stackNode *next;
}node;

typedef struct stack{
	struct stackNode *start;
	struct stackNode *top;
	int count;
}stack;


stack* createStack(int *success, int *e);

void push(stack *s,void *num,int *success, int *e);

void* pop(stack* s, int *success, int *e);

void clearStack(stack *s, int *success, int *e);

stack* releaseStack(stack *s, int *success, int *e);

#endif