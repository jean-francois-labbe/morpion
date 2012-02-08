#include "board.h"
#include "gameManager.h"
#include "display.h"
#include "stdio.h"

int main(void)
{
  int fini,x,y;
  fini=0;
  
  initPlayer();
  createBoard();
  while(!fini)
    {
      displayBoard();
      if(getPlayer()==CROSS)
        {
          printf("Cross to play\n");
        }
      else
        {
          printf("Circle to play\n");
        }
      printf("column?: ");
      scanf("%d",&x);
      printf("line?: ");
      scanf("%d",&y);
      if(putPiece(x,y,getPlayer())==0)
        {
          fini=checkGameStatus();
          if(!fini)
            {
              changePlayer();
            }
        }else
        {
          printf("you can't play here!\n");
        }
    }
  displayBoard();
  if(getPlayer()==CROSS)
    {
      printf("Cross won \\o/\n");
    }
  else
    {
      printf("Circle won \\o/\n");
    }
}
