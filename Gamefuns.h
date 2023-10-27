#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void game ();

void IniBoard (char GameBoard[ROW][COL]);

void ShowBoard(char GameBoard[ROW][COL]);