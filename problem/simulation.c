#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 10

typedef struct
{
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
}queue;

void queue_init(queue *q)
{
	q -> rear = -1;
	q -> front = -1;
}

int is_full(queue * q)
{
	if(q -> rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(queue *q)
{
	if(q -> front == q -> rear)
		return 1;
	else
		return 0;
}

void Enqueue(queue *q, int item)
{
	if(is_full(q))
	{
		printf("큐가 가득 찼습니다. \n");
	}
	q -> data[++(q -> rear)] = item;
}

int Dequeue(queue *q)
{
	if(is_empty(q))
	{
		printf("큐 안에 아무 것도 없음 \n");
	}
	int item = q -> data[++(q -> front)];

	return item;
}

void display(queue *q)
{
	if(is_empty(q))
	{
		printf("큐 안에 아무 것도 없음 \n");
	}
	else
	{
        for(int i = -1; i < MAX_QUEUE_SIZE; i++)
        {
            if ( i > q -> rear || i <= q -> front)
            {
                printf("   | ");
            }
            else
            {
                printf("%d   | ", q->data[i]);
            }
            
        }
		
		printf("\n");
	}
}

void size(queue *q)
{
    printf("%d개 \n", ((q -> rear) - (q -> front)));
}

int peek(queue *q)
{
    return q -> data[q -> front];
}

int random_rand(queue *q, int select)
{
    int rdata[MAX_QUEUE_SIZE * 2];
    int nresult = 0, mul = 1, sub = 100;
    int temp;
    
    srand(time(NULL));
    
    if(select == 2)
    {
        printf("몇을 기준으로 뺄셈을 수행하시겠습니까(default = 100)? \n");
        scanf("%d", &sub);
    }
    
    for(int i = 0; i <= MAX_QUEUE_SIZE - 1; i++)
    {
        int item = rand() % 10 + rand() % 10 / 10;
        
        if (select == 1)
        {
            nresult += item;
            Enqueue(q, item);
        }
        else if (select == 2)
        {
            sub -= item;
            Enqueue(q, item);
            if(i >= MAX_QUEUE_SIZE - 1)
            {
                nresult = sub;
            }
        }
        else if (select == 3)
        {
            mul *= item;
            Enqueue(q, item);
            if(i >= MAX_QUEUE_SIZE - 1)
            {
                nresult = mul;
            }
        }
        else
        {
            printf("다시 제대로 입력 부탁드리겠습니다. \n");
        }
        
        //printf("%d : %d \n", i, q -> data[i]);
    }
    
    
    return nresult;
}


void game_play(queue q, queue p)
{
    int sum = 0;
    int n = 0, answer = 0, difficulty = 0, select = 0;
    
    printf("난이도를 입력해주세요(1 : 어려움, 2 : 보통, 3 : 쉬움). \n");
    scanf("%d", &difficulty);
    
    printf("어떤 사칙연산에 대해서 수행하시겠습니까? \n");
    printf("1 : + \n2 : - \n3 : * \n");
    scanf("%d", &select);
    
    sum = random_rand(&q, select);
    
    p = q;
    
    while(n != MAX_QUEUE_SIZE)
    {
        system("clear");
        
        int item = Dequeue(&q);
        printf("|\t %d \t| \n", item);
        
        if (difficulty == 1)
        {
            for(int i=0; i<9000000; i++)
            {
                printf("");
            }
        }
        else if (difficulty == 2)
        {
            for(int i=0; i<14000000; i++)
            {
                printf("");
            }
        }

        else if (difficulty == 3)
        {
            for(int i=0; i<18000000; i++)
            {
                printf("");
            }
        }

        
        //printf("%d: %d \n", n+1, q.data[n]);
        n++;
    }
    
    printf("정답을 입력 부탁드리겠습니다(뺄셈의 경우 절댓값으로 입력 부탁드려요). \n");
    scanf("%d", &answer);
    
    if(answer == sum)
    {
        printf("정답입니다!! \n");
    }
    else
    {
        display(&p);
        printf("틀렸습니다. 정답은 %d 이네요ㅎㅎ \n", sum);
    }
}


int main()
{
	queue q, p;
    
	queue_init(&q);
    
    game_play(q, p);
    
	return 0;
}
