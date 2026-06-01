#include "game.h"
#define _CRT_SECURE_NO_WARNINGS
void initboard(char board[ROW][COL],int row,int col) {
	int i = 0, j = 0;
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0,j=0;
	/*for (i = 0;i < ROW;i++) {
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if(i<ROW-1)
			printf("---|---|---\n");
		}		*/
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			printf(" %c ", board[i][j]);
			if (j < COL - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < ROW - 1) {
			int j = 0;
			for (j = 0;j < COL ;j++) {
				printf("---");
				if (j < COL - 1) {
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	printf("玩家请输入:->\n");
	int x = 0, y = 0;
	while (1) {
		printf("请输入坐标:>");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && x <= row && y>0 && y <= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该位置已被占用，请重新输入\n");
		}
		else
			printf("非法输入，请重新进行输入位置\n");
	}
	
}

void ComputerMove(char board[ROW][COL], int row, int col) {
	printf("电脑输入中\n");
	while (1) {
		int x = 0, y = 0;
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] = ' ') {
			board[x][y] = '@';
			break;
		}
	}


}

int  isFull(char board[ROW][COL], int row, int col) {
	for (int i = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			if (board[i][j] == ' ')
				return 1;
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col) {
	//行
	int i = 0;
	for (i = 0;i < ROW;i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//列
	int j = 0;
	for (j = 0;j < COL;j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}
	//如果判定结束还没有赢家，则需要判定平局（棋盘）占满还是继续
	if (isFull(board, row, col)==1)
		return 'C';
	else
		return 'Q';
}