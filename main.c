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
	char(*PoBoard)[COL] = GameBoard;	//此处定义一个一维指针
	/*一维指针的作用：
		创建了一个容量为[COL]的char类型指针并指向GameBoard的开头
		每次希望调用GameBoard[i][j]时就可以用PoBoard[i][j]调用
			此处[j]为[COL]而[i]是（* PoBoard+i ）*/

			//初始化棋盘
	IniBoard(PoBoard);

	//打印棋盘
	ShowBoard(PoBoard);

	//游戏循环
	GameLoop(PoBoard);
}

int main() {
	srand((unsigned int)time(NULL));
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