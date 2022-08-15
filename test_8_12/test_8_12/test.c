#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()
{
	printf("***********************************************\n");
	printf("****               0.exit                 *****\n");
	printf("****               1.play                 *****\n");
	printf("***********************************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化棋盘
	InitBord(mine,ROW,COL,'0'); //'0'
	InitBord(show, ROW, COL,'*');//'*'
	//打印棋盘
	//DIsplayBoard(mine, ROW, COL);
	DIsplayBoard(show, ROW, COL);
	//布置雷
	Setmine(mine, ROW, COL);
	DIsplayBoard(mine, ROW, COL);
	//排查雷
	FindMine(mine,show ,ROW, COL);
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误,请重新选择\n");
			break;
		}

	} while (input);
	return 0;
}