#include <stdio.h>
#include<math.h>
#define N 4 /* �������̴�С */
static int sum; /* ��ǰ���ҵ���ĸ��� */
static int x[N]; 
int place(int k)
{
    int j; 
    for (j = 0; j < k; j ++)
        if (x[j] == x[k] || abs(j - k) == abs(x[j] - x[k])) 
return 0;
         return 1;
}
/* ��ӡ��� */ 
void chessboard()
{
    int i,j;
	int site[N];
     printf("��%d�ֽⷨ:\n", ++ sum); 
     for (i = 0; i < N; i ++) {
         for (j = 0; j < N; j ++)
             if (j == x[i]) {printf("Q ");site[i]=j+1;}
             else printf("* ");
     printf("\n");
	 }
	 printf("A%d(",sum);
	 for(i = 0; i < N; i ++)
	 {
		 printf("%d,",site[i]);
	 }
	 printf(");");
	 printf("\n");
}
/* ����������ռ� */
void backtrack()
{
    int k = 0;
    x[0] = -1;
    while (k >= 0) {
        x[k] += 1; /* ������һ�� */
        /* ���������������л���Է��ûʺ���� */
        while ((x[k] < N) && !(place(k))) x[k] += 1;
        if (x[k] < N) /* ������δ�Ƴ����� */
            if (k == N - 1) chessboard(); /* ���������һ�� */
            else x[++ k] = -1; /* ������һ�� */
        else k --; /* ���ݵ���һ�� */
    }
}
int main(void)
{
    backtrack();
	printf("%d�ʺ���%d����:\n",N,sum);
    return 0;
}

