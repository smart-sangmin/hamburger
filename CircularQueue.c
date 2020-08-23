#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void Queueinit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QisEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == Que_Len - 1)
		return 0;
	else
		return pos + 1;
}

void EnQueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!\n");
		exit(-1);
	}
	pq->rear=NextPosIdx(pq->rear);
	pq->QueueArr[pq->rear] = data;
}

Data DeQueue(Queue* pq)
{
	if (QisEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);

	return pq->QueueArr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		printf("Queue Memory Error\n");
		exit(-1);
	}
	return pq->QueueArr[NextPosIdx(pq->front)];
}
