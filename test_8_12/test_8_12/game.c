#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ������
void InitBord(char board[ROWS][COLS],int row,int col,char set)
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j <COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

//��ӡ����
void DIsplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("-----------����С��Ϸ---------------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------����С��Ϸ---------------\n");
}
//������
void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 10;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}		
	}
}

int CountMine(char mine[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int count = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (mine[i][j] == '1')
					count++;
			}
	}
	return count;
}
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int ret;
	int x = 0, y = 0;
	while (1)
	{
		printf("��������Ҫ�ߵ�λ��\n");
		scanf("%d%d", &x, &y);
		if(x>=1&&x<=row&&y>=1&&y<=col)
		{
			if (mine[x][y] != '1')
			{
				ret = CountMine(mine, x, y);
				show[x][y] = ret + '0';
				//��չ����
				ExpanndBoard(mine, show, x, y);
				DIsplayBoard(show, ROW, COL);
				if (show[x][y] == ' ')
				{
					printf("������Ϊ�ո������룬�����������������\n");
				}
			}
			
			else
			{
				printf("��Ǹ�㱻��ը����\n");
				DIsplayBoard(mine, ROW, COL);
				break;
			}
		}	
	}
}
//�Ż�
void ExpanndBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0, j = 0;
	int count = CountMine(mine, x, y);
	if (count == 0)
	{
		show[x][y] = ' ';
		if (show[x - 1][y - 1] == '*' && x - 1 > 0 && x - 1 < ROWS && y - 1 > 0 && y - 1 < COLS)
			ExpanndBoard(mine, show, x-1, y-1);
		if (show[x - 1][y] == '*' && x - 1 > 0 && x - 1 < ROWS && y  > 0 && y < COLS)
			ExpanndBoard(mine, show, x - 1, y );
		if (show[x -1][y + 1] == '*' && x - 1 > 0 && x - 1 < ROWS && y + 1 > 0 && y + 1 < COLS)
			ExpanndBoard(mine, show, x - 1, y + 1);
		if (show[x][y - 1] == '*' && x  > 0 && x  < ROWS && y - 1 > 0 && y - 1 < COLS)
			ExpanndBoard(mine, show, x , y - 1);
		if (show[x][y+1] == '*' && x  > 0 && x  < ROWS && y + 1 > 0 && y + 1 < COLS)
			ExpanndBoard(mine, show, x , y + 1);
		if (show[x + 1][y - 1] == '*' && x + 1 > 0 && x + 1 < ROWS && y - 1 > 0 && y - 1 < COLS)
			ExpanndBoard(mine, show, x + 1, y - 1);
		if (show[x + 1][y ] == '*' && x + 1 > 0 && x + 1 < ROWS && y > 0 && y  < COLS)
			ExpanndBoard(mine, show, x + 1, y );
		if (show[x + 1][y+1] == '*' && x + 1 > 0 && x + 1 < ROWS && y + 1 > 0 && y + 1 < COLS)
			ExpanndBoard(mine, show, x + 1, y + 1);
	}
	else
	{
		show[x][y] = count + '0';
		//DIsplayBoard(show, ROW, COL);
		
	}
}