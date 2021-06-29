
/*@
递归的三个条件
1. 递归必须得有一个明确的终止条件
2. 该函数处理问题的规模必须减少
3. 这个问题必须可解决
*/


/**
n个圆盘从下面开始按大小顺序摆放在A柱子上。并且规定，任何时候，在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘，求最少的移动步骤
*/
#include<stdio.h>

void hanoi(int n, char* A, char* B, char* C) {
    /*
    if n==1 
        将A 上的盘子直接移动到C
    else
        将A 上前n-1个盘子借助C 移动的B
        将A 上的第n个盘子移动到C
        将B 上的n-1 个盘子借助A 移动到C
    */

    if( n==1 ) {
        printf("move the plate %d from %s to %s directly\n", n, A, C );
    } 
    else {
        hanoi(n-1, A, C, B);
        printf("move the plate %d from %s to %s directly\n", n, A, C );
        hanoi(n-1, B, A, C);

    }

}

int main(void)
{
	char ch1[2] ='A';
	char ch2[2] ='B';
	char ch3[2] ='C';
	int n;

	printf("please input the number of plate \n");
	scanf("%d",&n);

	hanoi(n,ch1, ch2, ch3);

	return 0;
}
