#include "Gamefuns.h"

void menu() {
	printf("*****************************\n");
	printf("*******1.Start***************\n");
	printf("*******----------------******\n");
	printf("*******0.Exit****************\n");
	printf("*****************************\n");
}

//��Ϸ������
void game() {
	//��������
	char GameBoard[ROW][COL] = { 0 };
	char(*PoBoard)[COL] = GameBoard;	//�˴�����һ��һάָ��
	/*һάָ������ã�
		������һ������Ϊ[COL]��char����ָ�벢ָ��GameBoard�Ŀ�ͷ
		ÿ��ϣ������GameBoard[i][j]ʱ�Ϳ�����PoBoard[i][j]����
			�˴�[j]Ϊ[COL]��[i]�ǣ�* PoBoard+i ��*/

			//��ʼ������
	IniBoard(PoBoard);

	//��ӡ����
	ShowBoard(PoBoard);

	//��Ϸѭ��
	GameLoop(PoBoard);
}

int main() {
	srand((unsigned int)time(NULL));
	int uipt;
	do {
		menu();
		printf("Please select an option��>");
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