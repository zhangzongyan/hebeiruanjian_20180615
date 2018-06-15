/*
 完成日历:已知1990.1.1是星期一,求得输入的任意年月(1990后)对应的日历
 分析:
	2000/8 -----> 2000/8/1是星期几------>1990.1.1到2000.8.1有多少天--->1990~1999+2000.1.1~2000.8.1
	       -----> 2000/8整月有多少天	
 */

#include <stdio.h>

int isLeap(int year);
int dayofmonth(int month, int year);
int main(int argc, char **argv)
{
	int y, m;	
	int sumdays = 0;
	int weekday = 0;
	int monthdays = 0;
	int i;

	if (argc < 3) {
		printf("您输入的命令有误，请重新输入(./a.out m y)\n");
		return 1; //出错
	}

	m = atoi(argv[1]);
	y = atoi(argv[2]);

//	printf("请问您要查看日历的年月(year/month):");
//	scanf("%d/%d", &y, &m);

	// 计算1990~y-1
	for (i = 1990; i < y; i ++) {
		sumdays += (365 + isLeap(i));
	}
	// y.1.1~ y.m.1
	for (i = 1; i < m; i++) {
		sumdays += dayofmonth(i, y);
	}
	sumdays += 1; // m.1

	//y.m.1是星期几
	weekday = sumdays % 7;
	printf("%d/%d/1是星期%d\n", y, m, weekday);

	monthdays = dayofmonth(m, y);
	
	//打印
	printf("        %d月%d年\n", m, y);
	printf("sun mon thu wed thr fri sat\n");
	//根据1号是星期几，决定1号的位置
	for (i = 0; i < weekday; i++)
		printf("    ");
	for (i = 1; i <= monthdays; i++) {
		printf("%3d%c", i, (i+weekday) % 7 ? ' ': '\n');	
	}
	printf("\n");

	return 0;
}
/*
 *判断给定的年份是否为润年
function:
	isLeap()
args:
	year
return:
	1--->yes
	0--->no
 * */
int isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*
 *判断给定的月份的天数
 * */
int dayofmonth(int month, int year)
{
	int day;

	switch(month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			day = 31;
			break;
		case 4: case 6: case 9: case 11:
			day = 30;
			break;
		case 2:
			day = 28 + isLeap(year);
			break;
		default:
			day = -1;
			break;
	}	

	return day;
}


