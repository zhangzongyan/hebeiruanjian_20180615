#include <stdio.h>
#include <string.h>

void mysort(void *p, int nmemb, int size, int (* cmp)(const void *, const void *));

static int cmp_int(const void *data1, const void *data2)
{
	int *d1 = (int *)data1;
	int *d2 = (int *)data2;

	return *d2 - *d1;
}

static int cmp_str(const void *data1, const void *data2)
{
	char **d1 = (char **)data1;
	char **d2 = (char **)data2;

	return strcmp(*d1, *d2);
}

int main(void)
{
	int arr[] = {3,2,4,1,6,7,9,8,5};
	char *str[] = {"hello", "abort", "hi"};
	int i;

	mysort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), cmp_int);
	mysort(str, 3, sizeof(char *), cmp_str);

	printf("排序后:\n");
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
	printf("\n");

	for (i = 0; i < sizeof(str) / sizeof(str[0]); i ++)
		printf("%s ", str[i]);
	printf("\n");

	return 0;
}

/*
 *定义一个函数，可以为任意数组排序
 * void *p; p能存储任意类型的地址，但是p没有步长
 * */
void mysort(void *p, int nmemb, int size, int (* cmp)(const void *, const void *))
{
	int i, j;	
	char tmp[size];

	for (i = 0; i < nmemb-1; i++) {
		for (j = 0; j < nmemb-1-i; j++)	{
			// j   j+1	
			if (cmp((char *)p+j*size, (char *)p+(j+1)*size) > 0) {
				memcpy(tmp,(char *)p+j*size, size);			
				memcpy((char *)p+j*size,(char *)p+(j+1)*size, size);			
				memcpy((char *)p+(j+1)*size, tmp, size);			
			}
		}
	}

}


