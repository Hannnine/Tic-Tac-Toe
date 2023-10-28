#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void game ();

void IniBoard (char (*PoBoard)[COL]);

void ShowBoard(char (*PoBoard)[COL]);

void UserIpt(char(*PoBoard)[COL]);

void PCIpt(char(*PoBoard)[COL]);

void GameLoop(char(*PoBoard)[COL]);

void CheckWinner(char(*PoBoard)[COL]);