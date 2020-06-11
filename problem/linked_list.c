#include <stdio.h>
#include <stdlib.h>

// 노드 정의
typedef struct node
{
    int data;
    struct node * next;
}node;

// 노드 생성 (malloc()함수로 공간을 확보하여 데이터 삽입 후 생성된 공간의 주소를 반환)
node* create_node(int data)
{
    node *p;
    p = malloc(sizeof(node));
    p -> data  = data;
    p -> next = NULL;
    
    return p;
}

// 노드 추가
void append_node(node **head, node *newnode)
{
    node *ptr = *head;
    if(ptr == NULL)
    {
        *head = newnode;
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr->next = newnode;
    }
}

// 선택 위치에 노드 추가
void insert_after(node *ptr, node *newnode)
{
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
}

// 노드 삭제
void delete_node(node *head)
{
    node *ptr = head, *ptrs = NULL;
    
    while(ptr->next != NULL)
    {
        ptrs = ptr;
        ptr = ptr -> next;
    }
    
    ptrs -> next = NULL;
    
    free(ptr);
}

// 노드 가져오기 - 인덱스에 해당하는 노드를 가져옴
node *get_node(node *head, int index) {
    node *ptr = head;
    while(ptr -> next != NULL && index > 0)
    {
        index--;
        ptr = ptr -> next;
    }
    
    return ptr;
}

void print_list(node *head)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d \n", ptr -> data);
        ptr = ptr -> next;
    }
}

int main() {
    // linked list head pointer create
    node *head = NULL;
    node *ptr;
    
    // head를 이용하여 NULL을 찾은 후 알맞게 데이터 추가
    append_node(&head, create_node(1));
    append_node(&head, create_node(2));
    append_node(&head, create_node(3));
    append_node(&head, create_node(4));
    append_node(&head, create_node(5));
    
    // 느도 삭제
    delete_node(head);
    delete_node(head);
    
    // 전체 노드 출력
    print_list(head);
    
    // 인덱스 2에 해당하는 노드 가져오기
    ptr = get_node(head, 2);
    printf("index 2 : %d \n", ptr -> data);
    //인덱스 2 노드 뒤에 3의 값을 가지는 노드를 추가
    insert_after(ptr, create_node(3));
    printf("index 2 : %d \n", ptr -> data);
    
    // 전체 노드 출력
    print_list(head);
    
    return 0;
}
