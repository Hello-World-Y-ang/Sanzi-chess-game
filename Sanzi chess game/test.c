#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
int p;

void menu()
{
	printf("*****************************\n");
	Sleep(500);
	printf("-----Welcome---to---the------\n");
	Sleep(500);
	printf("-------------GAME------------\n");
	Sleep(500);
	printf("*****1. paly******0.exit*****\n");
	Sleep(500);
	printf("*****************************\n");
	
}

void start()
{
	int password = 123456;
	printf("请输入启动密码\n");
	scanf("%d", &p);
	while (password != p)
	{
		printf("密码错误，请重新输入（输入0退出）:\n");
		scanf("%d", &p);
		if (p == 0)
		{
			printf("已退出！！！\n");
			break;
		}
	}
}

//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组——存放走出的棋盘信息
	char board[ROW][COL] = { 0 };//全部为空格
	//初始化棋盘
	InitBoard(board,  ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == 'o')
	{
		printf("玩家赢\n");
	}
	else if (ret == 'x')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	start();
	if (p == 0)
	{
		return;
	}
	if (p == 123456)
	{
		system("cls");
		printf("密码正确\n");
	}
	do 
	{
		menu();
		printf("          请选择：> ");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			printf("三子棋\n");
			game();
			break;
		default:
			printf("选择错误，请重新进行选择：\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}