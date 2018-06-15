#include <stdio.h>

int main(void)
{
	/*
	int arr[3] = {1,2,3};

	printf("arr:%p\n", arr);
	printf("arr+1:%p\n", arr+1);

	printf("&arr:%p\n", &arr);
	printf("&arr+1:%p\n", &arr+1);
	*/
	int a[2][4] = {
		{1,3,4,5},
		{11,22,33,44}
	};

	printf("a:%p\n", a);
	printf("a+1:%p\n", a+1);
	printf("&a+1:%p\n", &a+1);

	printf("*a:%p\n", *a);
	printf("a[0]:%p\n", a[0]);
	printf("a[0]+5:%p\n", a[0]+5);

	printf("a[0][3]:%d\n", a[0][3]);
	printf("a[0][6]:%d\n", a[0][6]);

	return 0;
}

