#include<stdio.h>

int combination(int n, int k);

int main(void)
{
    int n_num, k_num, result_num=0;
    printf("이항 계수 n, k를 입력해주세요. \n");     
    scanf("%d %d", &n_num, &k_num);
    printf("n = %d, k = %d 입력 하였습니다. \n", n_num, k_num);
    result_num = combination(n_num, k_num);

    printf("%d 개중에 %d개를 선택하는 경우의 수 : %d \n", n_num, k_num, result_num);
    return 0;
}

int combination(int n, int k)
{
    if(n == k || k == 0) return 1;
    return combination(n-1, k-1) + combination(n-1, k);
}

int memoization_combination(int n, int k)
{
    int buf[100][100];

    if(buf[n][k]>0) return buf[n][k];

    if(n == k || k == 0) return 1;

    return buf[n][k] = combination(n-1, k-1) + combination(n-1, k);
}

