#pragma once
#include<stdio.h>
#include <stdlib.h>  
#include <time.h> 

#define ROWS ROW+2
#define COLS ROW+2
#define ROW 9
#define COL 9


//初始化棋盘
void InitBord(char mine[ROWS][COLS], int row, int col);
//打印棋盘
void DIsplayBoard(char mine[ROWS][COLS], int row, int col);
//布置雷
void Setmine(char mine[ROWS][COLS], int row, int col);
//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
//优化雷区
void ExpanndBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);