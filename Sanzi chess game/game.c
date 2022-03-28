#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
} 

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		//1.��ӡ�ָ���if (i < row - 1)
		for (j = 0;j < col;j++)
		{
			printf(" ---");
			if (j == col - 1)
			{
				printf("\n"); 
			}
		}
		//2.��ӡÿһ�е�����
		for (j = 0;j < col;j++)
		{
			printf("| %c ", board[i][j]);
			if (j == col - 1)
			{
				printf("|\n");
			}
		}
		if (i == row-1)
		{
			int y = 0;
			for (y = 0;y < col;y++)
			{
				printf(" ---");
				if (y == col - 1)
				{
					printf("\n");
				}
			}
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("******************\n");
	printf("*****��һغ�*****\n");
	printf("******************\n");
	printf("������Ҫ�µ����꣺(����+�ո�+����)\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'o';
				break;
			}
			else
			{
				printf("�������ѱ�ռ��\n");
			}
		}
		else
		{
			printf("���겻�������������룺(����+�ո�+����)\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("******************\n");
	printf("*****���Իغ�*****\n");
	printf("******************\n");
	while (1)
	{
		Sleep(666);
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}
	}
}

//����1��ʾ��������
//����0��ʾ����δ��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//δ��
			}
		}
	}
	return 1;//����
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�жϺ�����
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		} 
	}
	//�ж�������
	for (i = 0;i < col;i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	} 
	return 'C';
}
