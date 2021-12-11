#include<stdlib.h>

struct queueNode{
	int *value;
	struct queueNode *next;
}*temp;

typedef struct queueNode node;

struct queueList{
	node *front;
	node *rear;
	int count;
};

typedef struct queueList queue;

queue* createQueue(int *success, int *error){
	*success = *error = 0;
	queue *q = (queue*)malloc(sizeof(queue));
	if(q == NULL){
		*error = 1;
		return;
	}
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
	*success = 1;
	return q;
}

void enqueue(queue *q,int num, int *success, int *error){
	*success = *error = 0;
	if(q == NULL){
		*error = 2;
		return;
	}
	node *n = (node *)malloc(sizeof(node));
	if(n == NULL){
		*error = 1;
		return;
	}
	int *nm = (int *)malloc(sizeof(int));
	*nm = num;
	n->value = nm;
	n->next = NULL;
	if(q->front == NULL){
		q->front = n;
		q->rear = n;
		q->count++;
		*success = 1;
		return;
	}
	q->rear->next = n;
	q->rear = n;
	q->count++;
	*success = 1;
	return;
}

void dequeue(queue *q, int *success, int *error){
	*error = *success = 0;
	if(q == NULL){
		*error = 2;
		return;
	}
	if(q->front == NULL){
		*error = 1;
		return;
	}
	if(q->front == q->rear){
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
		q->count--;
		*success = 1;
		return;
	}
	temp = q->front;
	q->front = q->front->next;
	free(temp);
	q->count--;
	*success = 1;
	return;
}

void clearQueue(queue *q, int *success, int *error){
	*success = *error = 0;
	if(q == NULL){
		*error = 2;
		return;
	}
	if(q->front == NULL){
		*error = 1;
		return;
	}
	while(q->front != NULL){
		dequeue(q,success,error);
	}
	*success = 1;
}

queue* releaseQueue(queue *q,int *success, int *error){
	*success = *error = 0;
	if(q == NULL){
		return;
	}
	if(q->front != NULL){
		clearQueue(q,success,error);
	}
	free(q);
	*success = 1;
	return NULL;
}
