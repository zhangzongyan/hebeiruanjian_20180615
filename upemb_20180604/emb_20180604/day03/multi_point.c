#include <stdio.h>
#include <signal.h>

typedef int a; //a 整型

typedef int *po;// po int *型

void handler2(int s)
{
	alarm(1);
	printf("不好！\n");
}

void handler1(int s)
{
	static int i = 0;
	
	i ++;
	if (i == 5)
		signal(SIGALRM, handler2);

	alarm(1);
	printf("你好！\n");
}

int main(void)
{
	int arr[3] = {1,2,3};
	int *p = arr;
	int (*q)[3] = &arr;//数组指针

	signal(SIGALRM, handler1);
	alarm(1);

	printf("arr:%p\n", arr);//int *
	printf("arr+1:%p\n", arr+1);//int *

	printf("&arr:%p\n", &arr);// int (*)[3]
	printf("&arr+1:%p\n", &arr+1);

	printf("q+1:%p\n", q+1);

	while (1);

	return 0;
}

