#include <stdio.h>

int main(void)
{
	char str[] = "hebei";	
	// p q   常量(的)指针
	const char *p = str;
	char const *q = str;//p q没有区别, 含义相同
	//指针(的)常量
	char *const m = str;

	str[1] = 'i';
	//p[1] = 'a';
	printf("str:%s\n", str);

	m[1] = 'a';
	printf("str:%s\n", str);
	//m ++;m只读

	return 0;
}

