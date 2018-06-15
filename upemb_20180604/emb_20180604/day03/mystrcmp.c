#include <stdio.h>
#include <string.h>

int mystrcmp(const char *p, const char *q);
int main(void)
{
	char *p = "awo";
	char *q = "awo";
	int ret;

	ret = mystrcmp(p, q);
	printf("ret:%d\n", ret);

	return 0;
}

/*
 返回两个字符串中第一个不相等的字符ascii差值
 如果相等返回0
 * */
int mystrcmp(const char *p, const char *q)
{
	while (*p || *q) {
		if (*p != *q)
			return *p - *q;
		p ++;
		q ++;
	}

	return 0;
}

int mystrcmp2(const char *p, const char *q)
{
	int i = 0;

	while (p[i] || q[i]) {
		if (p[i] != q[i])	
			return p[i] - q[i];
		i ++;
	}

	return 0;
}

