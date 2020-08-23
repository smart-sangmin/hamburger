#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__
#define Que_Len 30

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _queue
{
	int front;
	int rear;
	Data QueueArr[Que_Len];
}Queue;

void Queueinit(Queue* pq);

int QisEmpty(Queue* pq);

void EnQueue(Queue* pq, Data data);

Data DeQueue(Queue* pq);

Data QPeek(Queue* pq);

#endif