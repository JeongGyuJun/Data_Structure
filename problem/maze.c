#include <stdio.h> 
#include <stdlib.h>
 
#define MAX_SIZE 100	//최대 이동 횟수 
#define MAZE_SIZE 10	//배열 크기 정하기  


typedef struct Goto_xy {	//미로 내 좌표 이동. 
    short x; 
    short y; 
}goto_xy;
 
typedef struct Stack {		//스택 구조를 이용한 좌표 이동. 
    goto_xy data[MAX_SIZE]; 
    int top; 
}stack; 

char maze[MAZE_SIZE][MAZE_SIZE]={	//미로 맵 만들기(S : Start, F : Finish, 0 : 이동 가능 경로, 1 : 이동 불가능 경로) 
    {'1','1','1','1','1','1','1','1','1','1'}, 
    {'S','0','1','0','1','0','0','0','0','1'}, 
    {'1','0','1','0','1','1','0','1','0','1'}, 
    {'1','0','1','1','1','0','0','1','1','1'}, 
    {'1','0','1','0','1','1','0','0','0','1'}, 
    {'1','0','1','0','1','0','0','1','0','1'}, 
    {'1','0','1','0','1','1','0','1','0','1'}, 
    {'1','0','0','0','1','0','0','1','0','1'}, 
    {'1','0','1','0','0','0','0','1','0','F'}, 
    {'1','1','1','1','1','1','1','1','1','1'}
}; 


int is_full(stack *p) {		//스택 MAX_SIZE 크기만큼 가득 찼을 경우 
    return (p->top == MAX_SIZE-1); 
} 

int is_empty(stack *p) {	//스택이 비었을 경우 
    return (p->top == -1); 
} 

void push(stack *p, goto_xy data) {	//스택이 가득차지 않았다면 top + 1 증가 후 x, y좌표 입력. 
    if(is_full(p)) { 
        printf("스택이 꽉찼습니다\n"); 
        return ; 
    } else { 
        p->top++; 
        p->data[p->top].x=data.x; 
        p->data[p->top].y=data.y; 
    } 
} 

goto_xy pop(stack *p) {		//스택이 비어있지 않다면 top에 있는 data 반환. 
    if(is_empty(p)) { 
        printf("스택이 비어있습니다\n"); 
        exit(1); 
    } 
    return p->data[(p->top)--]; 
}

void FindWay(stack *s, int x, int y) {		//미로 경로 범위 내에 포함 and 이동 경로이며 아직 안 지나간 곳이면 x, y 좌표 스택 구조에 입력. 
    if(x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE) 
        return ; 
    if(maze[x][y] != '1' && maze[x][y] != '.') { 
        goto_xy tmp; 
        tmp.x=x; 
        tmp.y=y; 
        push(s,tmp); 
    } 
} 

int main() {
    // 스택, xy 등 필요한 변수 선언. 
    stack s; 
    goto_xy m; 
    int i, j, x, y;
 
    s.top = -1; // stack top 초기화 
    
    for(i=0;i<MAZE_SIZE;i++) { 	  //시작지(S : Start) 탐색 
        for(j=0;j<MAZE_SIZE;j++) { 
            if(maze[i][j]=='S') { 
                m.x=i; 
                m.y=j; 
            } 
        } 
    }
 
    printf("미로 \n");
 
    for(int i=0; i<MAZE_SIZE; i++){    //위에서 선언한 배열 요소에 맞게 미로 시각화.	 
        for(int j=0; j<MAZE_SIZE; j++){ 
            if(maze[i][j]=='0'){ 
                printf("◻︎");
            }
            else if(maze[i][j]=='1'){ 
                printf("◼︎");
            }
            else { 
                printf("%c",maze[i][j]); 
            } 
        } 
        printf("\n"); 
    } 

    printf("\n이동 경로\n"); 
    printf("시작 (%d,%d) -> ",m.x,m.y);
 
    while(maze[m.x][m.y] != 'F') {	//도착지 (F : Finish)가 아니면 계속 반복. 
        x=m.x; 
        y=m.y; 
        maze[x][y]='.'; // 방문한 곳을 표시. 
    
        // 이동 가능한 곳을 탐색(찾으면 스택에 입력). 
        FindWay(&s,x+1,y); 
        FindWay(&s,x-1,y); 
        FindWay(&s,x,y+1); 
        FindWay(&s,x,y-1);
 
        if(is_empty(&s)) {	//스택이 비어있다면 이동경로를 찾을 수 없는 것으로 판단. 
            printf("이동경로를 찾을 수 없습니다. 실패 \n"); 
            return 0; 
        } 
        else {     //스택에 data가 있다면 top에 있는 data 반환. 
            m=pop(&s); // 현재 좌표를 변경 
            printf("(%d,%d) -> ",m.x,m.y); 
        } 
     }
 
     printf("도착\n"); 
     printf("탐색 성공\n");
 
     return 0;
}
