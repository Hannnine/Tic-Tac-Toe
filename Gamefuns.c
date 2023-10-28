#include "Gamefuns.h"

void IniBoard(char(*PoBoard)[COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			PoBoard[i][j] = ' ';
		}
	}
}

void ShowBoard(char(*PoBoard)[COL]) {
	printf("-------------\n");	//首行打印
	for (int i = 0; i < ROW; i++) {
		printf("|");
		for (int j = 0; j < COL; j++) {
			printf(" ");
			printf("%c", PoBoard[i][j]);
			printf(" ");
			if (j != COL - 1)
				printf("|");
		}	//每行打印棋盘
		printf("|\n");	//换行
		printf("-------------\n");//分界线或底行打印
	}
}

void UserIpt(char(*PoBoard)[COL]) {
	int i, j;
	printf("Choose a space to fill with your stone:> （Type \"1 1\" for example）\n");
	scanf("%d %d", &i, &j);
	if (PoBoard[i - 1][j - 1] != '0' && PoBoard[i - 1][j - 1] != '1')
		PoBoard[i-1][j-1] = '0';
	else {
		printf("There has been filled already!\n");
		UserIpt(PoBoard);	//递归调用函数
	}
    CheckWinner(PoBoard);
}

void PCIpt(char(*PoBoard)[COL]) {
	int i;
	int j;
	i = rand() % ROW + 1;
	j = rand() % COL + 1;
	if (PoBoard[i - 1][j - 1] != '0' && PoBoard[i - 1][j - 1] != '1')
		PoBoard[i - 1][j - 1] = '1';
	else
		PCIpt(PoBoard);		//同上递归
    ShowBoard(PoBoard);
    CheckWinner(PoBoard);
}

void GameLoop(char(*PoBoard)[COL]) {
	int cnt = 0;
	while (cnt <= 9) {
		/*游戏模块*/
		UserIpt(PoBoard);			//用户输入
        cnt++;
        if (cnt == 9) {
            printf("Finished! Try it again!\n");
            return;                 //防止输入完暴死
        }
		PCIpt(PoBoard);				//电脑输入
        cnt++;
	}
}

void CheckWinner(char(*PoBoard)[COL]) {
    int Ucnt = 0; //玩家计数
    int Pcnt = 0; //电脑计数

    int x, y;	//坐标

    //横向检验
    for (x = 0; x < ROW; x++) {
        for (y = 0; y < COL; y++) {
            if (PoBoard[x][y] == '0')
                Ucnt++;
            else if (PoBoard[x][y] == '1')
                Pcnt++;
        }
        if (Ucnt == 3 || Pcnt == 3)
            break;
        else
            Ucnt = Pcnt = 0;	//初始化
    }

    //纵向检验
    if (Ucnt != 3 && Pcnt != 3) {
        for (y = 0; y < COL; y++) {
            for (x = 0; x < ROW; x++) {
                if (PoBoard[x][y] == '0')
                    Ucnt++;
                else if (PoBoard[x][y] == '1')
                    Pcnt++;
            }
            if (Ucnt == 3 || Pcnt == 3)
                break;
            else
                Ucnt = Pcnt = 0;	//初始化
        }
    }

    //左斜检验
    if (Ucnt != 3 && Pcnt != 3) {
        y = 0;
        for (x = 0; x < ROW; x++) {
            if (PoBoard[x][y] == '0')
                Ucnt++;
            else if (PoBoard[x][y] == '1')
                Pcnt++;
            y++;
        }
        if (Ucnt != 3 && Pcnt != 3)
            Ucnt = Pcnt = 0;	//初始化
    }

    //右斜检验
    if (Ucnt != 3 && Pcnt != 3) {
        x = ROW - 1;
        for (y = 0; y < COL; y++) {
            if (PoBoard[x][y] == '0')
                Ucnt++;
            else if (PoBoard[x][y] == '1')
                Pcnt++;
            x--;
        }
        if (Ucnt != 3 && Pcnt != 3)
            Ucnt = Pcnt = 0;	//初始化	
    }

    if (Ucnt == 3) {
        printf("Player Win!\n");
        return;  // 结束程序
    }
    else if (Pcnt == 3) {
        printf("PC Win!\n");
        return;  // 结束程序
    }
}
