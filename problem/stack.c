#include<stdio.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];


int top = -1;

int IsEmpty()
{
    if(top<0)
        return 1;
    else
        return 0;

}

int IsFull()
{
    if(top>=MAX_STACK_SIZE - 1)
        return 1;
    else 
        return 0;
}

void push(int value)
{
    if(IsFull() == 1)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value;
}

int pop()
{
    if(IsEmpty() == 1)
        printf("스택이 비어있습니다.");
    else
        return stack[top--];
}

int peek()
{
    if(IsEmpty() == 1)
        printf("스택이 비어있습니다.");
    else
        return stack[top];
}

int malloc_size(int byte_size)
{
    return sizeof(int) * byte_size;
}

int main() 
{
    printf("일반 배열 선언하여 스택 사용 \n\n");
    push(3);
    push(6);
    push(9);

    printf("push(3 -> 6 -> 9) \n");

    printf("pop : %d \n", pop());

    int peek_a;
    peek_a = peek();

    printf("peek_a :  %d \n", peek_a);

    printf("pop : %d \n", pop());

    return 0;
}
