#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


menu() {
	printf("*********************************\n");
	printf("*******  1：进行游戏  0：退出游戏******\n");
}

void game() {
	char board[ROW][COL] = { 0 };
	initboard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (1) {
		PlayerMove(board, ROW, COL);
		char ret = IsWin(board, ROW, COL);
		if (ret == '*') {
		printf("玩家赢\n");
		DisplayBoard(board, ROW, COL);
		break;
		}
		if (ret == 'Q') {
			printf("平局\n");
			DisplayBoard(board, ROW, COL);break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			if (ret == '*')
				printf("玩家赢\n");break;
				DisplayBoard(board, ROW, COL);
			if (ret == '@')
				printf("电脑赢\n");break;
				DisplayBoard(board, ROW, COL);	
			if (ret == 'Q')
				printf("平局\n");break;
				DisplayBoard(board, ROW, COL);	
		}
		DisplayBoard(board, ROW, COL);
	}
}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();//打印菜单
		printf("请输入\n");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("进入游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
	}
	} while (input);
	return 0;
}