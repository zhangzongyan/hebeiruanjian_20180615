/*
 *定义一个函数，得到数组的最大值，要求函数的返回值一定是void
 * */
#include <stdio.h>

void maxarr(int *p, int n, int *max)
{
	int i;

	//*p--->*(p+0) --->p[0]
	*max = p[0];
	for (i = 1; i < n; i++) {
		if (*(p+i) /*p[i]*/ > *max)
			*max = p[i];
	}
}

int main(void)
{
	int arr[10] = {1,5,2,9,4,10,17,1,2,3};
	int m;

	maxarr(arr, 10, &m);
	printf("最大值是%d\n", m);

	return 0;
}

