#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>

int arr[4][4] = {
	{0,0,0,0},
	{0,1,1,0},
	{0,0,1,1},
	{0,0,0,0}
};
static int row = 1, col = 1; 

void draw_arr(void);
static void sig_handler(int s)
{
	alarm(1);
	row += 2;	
	draw_arr();
}

//vt控制码
int main(void)
{
	int ch;
	struct termios old, new;

	//获取当前的输入模式
	tcgetattr(0, &old);
	//设置：不回显，无缓存
	new = old;
	new.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	tcsetattr(0, TCSANOW, &new);

	//改变信号的行为
	signal(SIGALRM, sig_handler); // man 2 signal
	alarm(1); // 5秒后产生SIGALRM信号, 此信号的默认行为是使得进程终止
	//printf("\33[35m\33[10;20Hnice to meet you!\n");
	draw_arr();
	
	while(1) {
		ch = getchar();	
		if (ch == 'q') {
			printf("\33[2J");
			printf("游戏结束\n");
			break;
		}
		switch (ch) {
			case 'a':
				col -= 2;
				break;
			case 's':
				row += 2;
				break;
			case 'd':
				col += 2;
				break;
			case 'w':
				row -= 2;
				break;
		}
	}
	//恢复
	tcsetattr(0, TCSANOW, &old);

	return 0;
}

/* *定义一个函数：遍历数组，将数组中所有为1的元素打印[]
 *
 * */
void draw_arr(void)
{
	int i, j;
	int color;

	srand(time(NULL));
	color = rand() % 8;
	//清屏
	printf("\33[2J");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)	{
			if (arr[i][j]) {
				printf("\33[%dm\33[%d;%dH[]", 30+color,row+i, col+j*2);	
				//关闭所有的vt属性
				printf("\33[0m");
				fflush(NULL);//刷新缓存区
				printf("\33[?25l");//隐藏光标
			}
		}
	}
}


