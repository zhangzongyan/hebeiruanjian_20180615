#include <stdio.h>

int main(void)
{
	//变量的定义
	int var;			
	//初始化
	int num = 100;
	
	//赋值
	var = 200;

	//相同类型变量的集合
	int arr[10] = {1,8,3,9,1,12};
	int *p = arr;

	printf("数组的收地址是arr:%p\n", arr);
	printf("arr+1:%p\n", arr+1);

	printf("&arr:%p\n", &arr);
	printf("&arr+1:%p\n", &arr+1);

	printf("*(arr+1):%d\n", *(arr+1));
	printf("*arr+1:%d\n", *arr+1);

	printf("p+3:%p\n", p+3);
	printf("p[4]:%d\n", p[4]);
	printf("*p++:%d\n", *p++);
	printf("*p++:%d\n", (*p)++);
	printf("*p:%d\n", *p);
	printf("p[2]:%d\n", p[2]);

	return 0;
}

