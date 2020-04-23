#include<stdio.h>


int move_N = 0;

void move(int N, char start, char to)
{
    printf("%d 원반을 %c 에서 %c로 이동\n", N, start, to);
    move_N++;
}

int hanoi_top(int N, char start, char to, char arrive)
{
    if (N == 1)
    {
        move(1, start, to);
        return move_N;
    }
    else
    {
        hanoi_top(N-1, start, arrive, to);
        move(N, start, to);
        hanoi_top(N-1, arrive, to, start);
        return move_N;
    }
}

int main(void)
{
    int result_N = 0;
    result_N = hanoi_top(5, 'A', 'B', 'C');
    printf("총 %d 원반을 이동하였습니다.\n", result_N);
    return 0;
}

