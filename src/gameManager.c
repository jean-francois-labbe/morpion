#include "board.h"
#include "gameManager.h"
#include "stdio.h"

int player;


int initPlayer()
{
  player=CROSS;
  return 0;
}

int changePlayer()
{
  if(getPlayer()==CROSS)
    {
      player=CIRCLE;
    }else
    {
      player=CROSS;
    }
  return player;
}

int getPlayer()
{
  return player;
}


int checkGameStatus()
{
  int i,j,result=0;
  
  for(i=0;i<WIDTH;i++)
    {
      if((getBoardCell(i,0)==getBoardCell(i,1))
         &&(getBoardCell(i,2)==getBoardCell(i,1))
         &&(getBoardCell(i,2)==getBoardCell(i,0))
         &&getBoardCell(i,0)!=EMPTY)
        {      
          result=getBoardCell(i,0);
        }
    }

  for(j=0;j<HEIGHT;j++)
    {
      if((getBoardCell(0,j)==getBoardCell(1,j))
         &&(getBoardCell(2,j)==getBoardCell(1,j))
         &&(getBoardCell(2,j)==getBoardCell(0,j))
         &&getBoardCell(0,j)!=EMPTY)
        {      
          result=getBoardCell(0,j);
        }
    }

      if((getBoardCell(0,0)==getBoardCell(1,1))
         &&(getBoardCell(2,2)==getBoardCell(1,1))
         &&(getBoardCell(2,2)==getBoardCell(0,0))
         &&getBoardCell(0,0)!=EMPTY)
        {      
          result=getBoardCell(0,0);
        }

      if((getBoardCell(0,2)==getBoardCell(1,1))
         &&(getBoardCell(2,0)==getBoardCell(1,1))
         &&(getBoardCell(2,0)==getBoardCell(0,2))
         &&getBoardCell(0,2)!=EMPTY)
        {      
          result=getBoardCell(0,2);
        }


  return result;
}


/*
int checkGameStatus(){
  int result=0;
  if((getBoardCell(0,0)==getBoardCell(1,0))&&(getBoardCell(1,0)==getBoardCell(2,0))&&(getBoardCell(0,0)==getBoardCell(2,0))&&getBoardCell(0,0)!=EMPTY)
    {      
      result=getBoardCell(0,0);
    }
  if((getBoardCell(0,1)==getBoardCell(1,1))&&(getBoardCell(1,1)==getBoardCell(2,1))&&(getBoardCell(0,1)==getBoardCell(2,1))&&getBoardCell(0,1)!=EMPTY)
    {    
      result=getBoardCell(0,1);
    }
  if((getBoardCell(0,2)==getBoardCell(1,2))&&(getBoardCell(1,2)==getBoardCell(2,2))&&(getBoardCell(0,2)==getBoardCell(2,2))&&getBoardCell(0,2)!=EMPTY)
    {
      result=getBoardCell(0,2);
    }
  return result;
}


*/
