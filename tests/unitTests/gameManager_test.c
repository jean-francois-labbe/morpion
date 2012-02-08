#include "gameManager.h"
#include "board.h"

#include "gtest/gtest.h"

TEST(GameManager, Line0Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,0,CROSS));
  EXPECT_EQ(0, putPiece(1,0,CROSS));
  EXPECT_EQ(0, putPiece(2,0,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, Line1Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,1,CROSS));
  EXPECT_EQ(0, putPiece(1,1,CROSS));
  EXPECT_EQ(0, putPiece(2,1,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, Line2Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,2,CROSS));
  EXPECT_EQ(0, putPiece(1,2,CROSS));
  EXPECT_EQ(0, putPiece(2,2,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, Column0Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,0,CROSS));
  EXPECT_EQ(0, putPiece(0,1,CROSS));
  EXPECT_EQ(0, putPiece(0,2,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}
TEST(GameManager, Column1Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(1,0,CROSS));
  EXPECT_EQ(0, putPiece(1,1,CROSS));
  EXPECT_EQ(0, putPiece(1,2,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}
TEST(GameManager, Column2Win) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(2,0,CROSS));
  EXPECT_EQ(0, putPiece(2,1,CROSS));
  EXPECT_EQ(0, putPiece(2,2,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, Diagonal) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,0,CROSS));
  EXPECT_EQ(0, putPiece(1,1,CROSS));
  EXPECT_EQ(0, putPiece(2,2,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, Diagonal2) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, checkGameStatus());
  EXPECT_EQ(0, putPiece(0,2,CROSS));
  EXPECT_EQ(0, putPiece(1,1,CROSS));
  EXPECT_EQ(0, putPiece(2,0,CROSS));  
  EXPECT_EQ(CROSS, checkGameStatus());
}

TEST(GameManager, initialisationPlayer) {
  EXPECT_EQ(0,initPlayer());
    EXPECT_EQ(CROSS,getPlayer());
}

TEST(GameManager, changePlayer) {
  EXPECT_EQ(0,initPlayer());
  EXPECT_EQ(CROSS,getPlayer());
  EXPECT_EQ(CIRCLE,changePlayer());
  EXPECT_EQ(CIRCLE,getPlayer());
  EXPECT_EQ(CROSS,changePlayer());
  EXPECT_EQ(CROSS,getPlayer());
}


