#include<stdio.h>
#include<stdlib.h>
#include<queue.h>

typedef struct queueList queue;

int main(){
	int s,e;
	queue *q = createQueue(&s,&e);
	enqueue(q,10,&s,&e);
	enqueue(q,40,&s,&e);
	enqueue(q,30,&s,&e);
	clearQueue(q,&s,&e);
	enqueue(q,45,&s,&e);
	q = releaseQueue(q,&s,&e);
	return 0;
}