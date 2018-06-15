#include <stdio.h>

void swap2num(int *num1, int *num2);
int main(void)
{
	int n, m;

	n = 200; 
	m = 10;

	printf("before, n:%d, m:%d\n", n, m);
	swap2num(&n, &m);
	printf("after, n:%d, m:%d\n", n, m);

	return 0;
}

/*
 *定义一个函数，实现两个整型数的交换
 * */
void swap2num(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

