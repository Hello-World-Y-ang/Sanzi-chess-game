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
	printf("��������������\n");
	scanf("%d", &p);
	while (password != p)
	{
		printf("����������������루����0�˳���:\n");
		scanf("%d", &p);
		if (p == 0)
		{
			printf("���˳�������\n");
			break;
		}
	}
}

//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	//���顪������߳���������Ϣ
	char board[ROW][COL] = { 0 };//ȫ��Ϊ�ո�
	//��ʼ������
	InitBoard(board,  ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == 'o')
	{
		printf("���Ӯ\n");
	}
	else if (ret == 'x')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("������ȷ\n");
	}
	do 
	{
		menu();
		printf("          ��ѡ��> ");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			printf("������\n");
			game();
			break;
		default:
			printf("ѡ����������½���ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}