#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//显示游戏的四种状态
//①玩家赢 --- 'o
//②电脑赢 --- 'x'
//③平局   --- 'Q'
//④继续   --- 'C'
char IsWin(char board[ROW][COL], int row, int col);