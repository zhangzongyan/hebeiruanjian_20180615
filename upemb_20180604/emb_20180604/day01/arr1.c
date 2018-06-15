#include <stdio.h>

int main(void)
{
	//定义
	int arr[10];//定义10个int类型的变量有区别吗
	//初始化数组
	char arr2[5] = {1,2,3,4,5};
	int i;
	
	//下标
	for (i = 0; i < 5; i++) {
		printf("%d\n", i[arr2]);
		printf("%d\n", *(arr2+i));
	}	

	printf("arr2:%p\n", arr2);
	printf("arr2+1:%p\n", arr2+1);
	//arr++; // arr = arr+1 xxxxx


	return 0;
}

