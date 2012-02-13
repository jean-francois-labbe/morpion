#include "board.h"
#include "gameManager.h"
#include "display.h"
#include <gtk/gtk.h>

#define size 9
char *values[size] = { "", "", "",
                       "", "", "",
                       "", "", ""};

GtkWidget * buttons[size+1];
int gameOver=0;
GtkWidget *imageCross,*imageCircle;

static void callback( GtkWidget *widget,
                      gpointer   data )
{   
  int i,x,y,player;
  if(!gameOver)
    {
      for(i=1;i<size+1;i++)
        {
          if(widget==buttons[i])
            {
              if(i>=0 && i<4)
                {
                  y=0;
                  x=i-1;
                }
              else
                {
                  if(i>=4 && i<7)
                    {
                      y=1;
                      x=i-4;
                    }
                  else
                    {
                      y=2;
                      x=i-7;
                    }
                }
              player=getPlayer();
              if(putPiece(x,y,player)==0)
                {
                   if(getPlayer()==CROSS)
                    {
                       gtk_button_set_image((GtkButton *) widget,(GtkWidget *) gtk_image_new_from_file("src/GTK/cross.png"));
                     }
                  else
                    {
                      imageCircle = gtk_image_new_from_file("src/GTK/circle.png");
                      gtk_button_set_image((GtkButton *) widget,(GtkWidget *) imageCircle);
                     }
                  gameOver=checkGameStatus();
                  if(!gameOver)
                    {
                      changePlayer();
                    }
                }
              else
                {
                  printf("Pas possible\n");
                }
            }
        }
    }
  
  //displayBoard();
  if(gameOver)
    {
      if(getPlayer()==CROSS)
        {
          printf("Cross won \\o/\n");
        }
      else
        {
          printf("Circle won \\o/\n");
        }
    }
}

int main( int argc, char *argv[])
{

  GtkWidget *window;

  GtkWidget *table;
  GtkWidget *button;


  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 180, 180);
  gtk_window_set_title(GTK_WINDOW(window), "GtkTable");

  gtk_container_set_border_width(GTK_CONTAINER(window), 5);
   
  table = gtk_table_new(3, 3, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);


  int i = 0;
  int j = 0;
  int pos = 0;

   for( i=0; i < 3; i++) {
    for( j=0; j < 3; j++) {
      button = gtk_button_new_with_label(values[pos]);
      buttons[((1+j))+((i*3))]=button;
      g_signal_connect (button, "clicked",G_CALLBACK (callback), (gpointer) "button 1");
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1 );
      pos++;
    }
  }

   gtk_window_set_title(GTK_WINDOW(window),"OXO");
   
  gtk_container_add(GTK_CONTAINER(window), table);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
                           G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  gtk_widget_show_all(window);
 GtkSettings *default_settings = gtk_settings_get_default();
  g_object_set(default_settings, "gtk-button-images", TRUE, NULL); 


  createBoard();
  initPlayer();
  
  gtk_main();

  return 0;
}
