#ifndef BOARD_H_
#define BOARD_H_

#define HEIGHT 3
#define WIDTH 3

#define EMPTY 0
#define CROSS 1
#define CIRCLE 2


int createBoard();
int getBoardCell(int x,int y);
int putPiece(int x, int y,int player);

#endif
