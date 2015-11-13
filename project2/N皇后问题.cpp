#include <stdio.h>
#include<math.h>
#define N 4 /* 定义棋盘大小 */
static int sum; /* 当前已找到解的个数 */
static int x[N]; 
int place(int k)
{
    int j; 
    for (j = 0; j < k; j ++)
        if (x[j] == x[k] || abs(j - k) == abs(x[j] - x[k])) 
return 0;
         return 1;
}
/* 打印棋局 */ 
void chessboard()
{
    int i,j;
	int site[N];
     printf("第%d种解法:\n", ++ sum); 
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
/* 回溯搜索解空间 */
void backtrack()
{
    int k = 0;
    x[0] = -1;
    while (k >= 0) {
        x[k] += 1; /* 向右移一列 */
        /* 向右移至出最右列或可以放置皇后的列 */
        while ((x[k] < N) && !(place(k))) x[k] += 1;
        if (x[k] < N) /* 向右移未移出棋盘 */
            if (k == N - 1) chessboard(); /* 已移至最后一行 */
            else x[++ k] = -1; /* 向下移一行 */
        else k --; /* 回溯到上一行 */
    }
}
int main(void)
{
    backtrack();
	printf("%d皇后有%d个解:\n",N,sum);
    return 0;
}

