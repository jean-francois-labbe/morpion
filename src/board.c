#include "board.h"

int Board[WIDTH][HEIGHT];

int createBoard()
{
  int i,j;
  for(i=0;i<WIDTH;i++)
    {
      for(j=0;j<HEIGHT;j++)
        {
          Board[i][j]=EMPTY;
          }
    }
  return 0;
}

int getBoardCell(int x, int y)
{

  return Board[x][y];
  
}

int putPiece(int x, int y,int player)
{
  int result=0;
  
  if(x<WIDTH && x>=0 && y<HEIGHT && y >=0)
    {
      Board[x][y]=player;
      result=0;
    }
  else
    {
      result=1;
    }

  return result;
}
