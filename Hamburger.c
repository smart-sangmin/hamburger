#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue q;

	Queueinit(&q);
	srand(time(NULL));

	//for문의 1회 회전은 1초의 시간 흐름을 의미
	for (sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)//15s 마다 손님이 들어옴
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				EnQueue(&q, CHE_TERM);
				cheOrder += 1;
				break;

			case BUL_BUR:
				EnQueue(&q, BUL_TERM);
				bulOrder += 1;
				break;

			case DUB_BUR:
				EnQueue(&q, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}

		if (makeProc <= 0 && !QisEmpty(&q))
			makeProc = DeQueue(&q);
		
		makeProc--;
	}
	printf("cheese burger: %d\n", cheOrder);
	printf("bulgogi burger: %d\n", bulOrder);
	printf("Double burger: %d\n", dubOrder);
	printf(" -Waitting room: %d\n", Que_Len);

	return 0;
}