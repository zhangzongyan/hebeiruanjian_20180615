#include <stdio.h>

int main(void)
{
	char str[] = "beautiful girl";
	char *p = str;

	printf("*p++:%c\n", *p++); //'b'
	printf("(*p)++:%c\n", (*p)++);//'e' ++作用于(*p)
	printf("*(p++):%c\n", *(p++));//'f'
	printf("*++p:%c\n", *++p);//'u'
	printf("++*p:%c\n", ++*p);//'v'

	return 0;
}

