#include <stdio.h>

#define NUM 10

int main(void)
{
	int arr[NUM] = {}; // 值随机产生的，从小到大排序
	int i, j, tmp;
	int num1, num2;

	num1 = 10;
	num2 = 15;

	printf("num1:%d, num2:%d\n", num1, num2);
	num1 = num1 ^ num2;
	num2 = num1 ^ num2; //(num1 ^ num2) ^ num2 == num1 ^ (num2 ^ num2) = num1 ^ 0 = num1
	num1 = num1 ^ num2; //(num1 ^ num2) ^ num1 == (num1 ^ num1) ^ num2 == num2
	printf("num1:%d, num2:%d\n", num1, num2);

	srand(getpid());
	// 产生值
	for (i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);	
	}	
	printf("\n");

	//冒泡排序
	//控制比较的次数	
	for (i = 0; i < NUM-1; i++) {
		//当前这次比较，要比较哪些元素
		for (j = 0; j < NUM-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}		
	}

	//输出结果
	for (i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");

	return 0;
}

