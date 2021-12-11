#ifndef QUEUE_0623_
#define QUEUE_0623_

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

queue* createQueue(int *success, int *error);

void enqueue(queue *q,int num, int *success, int *error);

void dequeue(queue *q, int *success, int *error);

void clearQueue(queue *q, int *success, int *error);

queue* releaseQueue(queue *q,int *success, int *error);

#endif