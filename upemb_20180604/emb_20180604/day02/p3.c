
#include <stdio.h>

/*
   字符串:字符的集合，'\0'结尾,字符间地址连续,
   字符数组:数组中的每一个元素都是字符
   字符串数组(概念不存在):可以用一个字符串为字符数组赋值

	作业:
		1.定义一个函数，实现求得字符串的长度

		2.定义一个函数:将src对应的字符串复制到dest目的地址中，返回字符串的字节个数
			int mystrcpy(char *dest, char *src);

 */

int main(void)
{
	//str 字符(串)数组
	char str[] = "hello";
	char *p = "world";// 将字符串常量"world"的首地址赋值给p

	str[2] = 'm';
	printf("%s\n", str);//"hemlo"

	//p[1] = 'n';


	return 0;
}

