#include "display.h"
#include "board.h"
#include "stdio.h"

void displayBoard()
{
  int i,j;
  for(j=0;j<HEIGHT;j++)
    {
      printf("|");
      for(i=0;i<WIDTH;i++)
        {
          if(getBoardCell(i,j)==CROSS)
            {
              printf("X");
            }
          else
            {
              if(getBoardCell(i,j)==CIRCLE)
                {
                  printf("O");
                }
              else
                {
                  printf(" ");
                }
            }
          printf("|");
        }
      printf("\n");
    }
}

