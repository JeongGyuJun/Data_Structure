#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct 
{
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}QueueType;

void init_queue(QueueType *q)
{
	q -> rear = -1;
	q -> front = -1;
}

void display(QueueType *q)
{
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d  | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType *q)
{
	if(q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType *q)
{
	if(q->rear == q->front)
		return 1;
	else
		return 0;
}

void size(QueueType *q)
{
        if(is_empty(q))
        {
                printf("큐의 현재 공간 : 0개 \n");
        }
	else
        	printf("큐의 현재 공간 : %d개 \n", (q -> rear - q -> front));

}

void peek(QueueType *q)
{
	if(is_empty(q))
	{
		printf("큐에 아무 것도 없음  \n");
	}
	else
		printf("%d \n", q -> data[(q -> front + 1)]);
}

void enqueue(QueueType *q, int item)
{
	if(is_full(q))
	{
		printf("큐가 가득참 \n");
	}
	
	q -> data[++(q -> rear)] =  item;
}

int dequeue(QueueType *q)
{
	if(is_empty(q))
	{
		printf("큐에 아무 것도 없음 \n");
	}
	
	int item = q -> data[++(q -> front)];
	
	return item;
}

int main()
{
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); display(&q);
	enqueue(&q, 20); display(&q);
	size(&q);
	enqueue(&q, 30); display(&q);

	peek(&q);
	item = dequeue(&q); display(&q);
	size(&q);
	item = dequeue(&q); display(&q);
	item = dequeue(&q); display(&q);
	size(&q);

	return 0;
}


