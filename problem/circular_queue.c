#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct
{
    int data[MAX_QUEUE_SIZE];
    int front, rear;
} queue;

void queue_init(queue *q)
{
    q -> rear = q -> front = 0;
}

int Is_empty(queue *q)
{
    return (q -> front == q -> rear);
}

int Is_full(queue *q)
{
    return ((q -> rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

void Enqueue(queue *q, int item)
{
    if(Is_full(q))
        printf("큐가 꽉 찼습니다.");
    
    q -> data[++(q->rear) % MAX_QUEUE_SIZE] = item;
}

int Dequeue(queue *q)
{
    if(Is_empty(q))
        printf("큐에 아무것도 없네요.");
    int item = q -> data[++(q -> front) % MAX_QUEUE_SIZE];
    return item;
}

void queue_peek(queue *q)
{
    if(Is_empty(q))
        printf("큐에 아무것도 없네요.");
    int item = q -> data[q -> front % MAX_QUEUE_SIZE];
    
    printf("다음 반환 데이터는 %d 입니다. \n", item);
}

void queue_display(queue *q)
{
    int i = q -> front;
    
    while(i-1 < q -> rear)
    {
        int item = q -> data[i % MAX_QUEUE_SIZE];
        
        printf("%d    |", item);
        
        ++i;
    }
    
    printf("\n");
    printf("front, rear : %d, %d \n", q -> front, q -> rear);
}


int main()
{
    queue q;
    
    queue_init(&q);
    
    int i = 0;
    while(!Is_full(&q))
    {
        Enqueue(&q, i);
        
        i++;
    }
    
    queue_display(&q);
    
    queue_peek(&q);
    
    while(!Is_empty(&q))
    {
        int item = Dequeue(&q);
        
        printf("%d  |", item);
    }
    
    return 0;
}
