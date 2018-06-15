#include <stdio.h>

void mystrlen(const char *p1, int *len);
int mystrcpy(char *dest, const char *src);
int main(void)
{
	char *p = "hello world";
	int n;
	char str[] = "nice to meet you boy";
	
	mystrlen(p, &n);

	printf("%s的长度是%d\n", p, n);

	n = mystrcpy(str, p);
	printf("str:%s\n", str);

	return 0;
}

/*
	计算字符串的长度 
  */
void mystrlen(const char *p1, int *len)
{
	int i; 

	for (i = 0; p1[i] != '\0'; i++) 
		;

	*len = i;
}

/*
	字符串复制
 */
int mystrcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;	
	}
	dest[i] = 0;
	
	return i;
}


