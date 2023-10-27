#include "Gamefuns.h"

void IniBoard(char GameBoard[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			GameBoard[i][j] = '*';
		}
	}
}

void ShowBoard(char GameBoard[ROW][COL]) {
	for (int i = 0; i < ROW; i++) {
		for(int j =0;j<COL;j++){
			printf("%c", GameBoard[i][j]);
			if (j != COL - 1)
				printf("|");
		}
		printf("\n");
		if (i != ROW - 1)
			printf("---------\n");
	}
}