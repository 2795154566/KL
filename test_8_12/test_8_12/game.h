#pragma once
#include<stdio.h>
#include <stdlib.h>  
#include <time.h> 

#define ROWS ROW+2
#define COLS ROW+2
#define ROW 9
#define COL 9


//��ʼ������
void InitBord(char mine[ROWS][COLS], int row, int col);
//��ӡ����
void DIsplayBoard(char mine[ROWS][COLS], int row, int col);
//������
void Setmine(char mine[ROWS][COLS], int row, int col);
//�Ų���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//�Ż�����
void ExpanndBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);