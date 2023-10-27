#include "Gamefuns.h"

void menu() {
	printf("*****************************\n");
	printf("*******1.Start***************\n");
	printf("*******----------------******\n");
	printf("*******0.Exit****************\n");
	printf("*****************************\n");
}

//游戏主函数
void game() {
	//定义容量
	char GameBoard[ROW][COL] = { 0 };

	//初始化棋盘
	IniBoard(GameBoard);

	//打印棋盘
	ShowBoard(GameBoard);

	//用户输入

	//电脑输入

	//结果判断
}

int main() {
	int uipt;
	do {
		menu();
		printf("Please select an option：>");
		scanf("%d", &uipt);
		switch (uipt) {
		case 0:
			printf("Thx 4 ur playing!\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("Sorry you may input wrong!\n");
			break;
		}
	} while (uipt);
	return 0;
}