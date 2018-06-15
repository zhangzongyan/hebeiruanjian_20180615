#include <stdio.h>

/*定义一个有20个整型元素组成的数组，数组成员值随机产生，求得数组中的最大最小值和平均值
 * */
#define NUM	20

int main(void)
{
	int arr[NUM] = {};
	int i;
	int max, min, sum = 0;//max min值是随机值

	srand(getpid());
	
	for (i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
		if (i == 0) {
			//数组的第一个元素
			max = min = arr[i];
		} else {
			if (arr[i] > max)	
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];
		}
		sum += arr[i];
	}
	printf("\n");

	printf("最大值:%d, 最小值:%d, 平均值:%d\n", max, min, sum / NUM);

	return 0;
}

