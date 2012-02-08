#include "board.h"

#include "gtest/gtest.h"

TEST(Board_test, CreateBoard) {
  EXPECT_EQ(0, createBoard());

  EXPECT_EQ(EMPTY,getBoardCell(0,0));
  EXPECT_EQ(EMPTY,getBoardCell(0,1));
  EXPECT_EQ(EMPTY,getBoardCell(0,2));

  EXPECT_EQ(EMPTY,getBoardCell(1,0));
  EXPECT_EQ(EMPTY,getBoardCell(1,1));
  EXPECT_EQ(EMPTY,getBoardCell(1,2));

  EXPECT_EQ(EMPTY,getBoardCell(2,0));
  EXPECT_EQ(EMPTY,getBoardCell(2,1));
  EXPECT_EQ(EMPTY,getBoardCell(2,2));
}

TEST(Board_test,putPieceOnBoard) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, putPiece(0,0,0));
  EXPECT_EQ(0, putPiece(0,1,CROSS));
  EXPECT_EQ(CROSS,getBoardCell(0,1));

  EXPECT_EQ(0, putPiece(0,2,CIRCLE));
  EXPECT_EQ(CIRCLE,getBoardCell(0,2));
}

TEST(Board_test,putPieceOutsideTheBoard) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(1, putPiece(-1,0,0));
  EXPECT_EQ(1, putPiece(0,3,CROSS));
  EXPECT_EQ(EMPTY,getBoardCell(0,1));

  EXPECT_EQ(1, putPiece(3,3,CIRCLE));
  EXPECT_EQ(EMPTY,getBoardCell(0,2));
}


TEST(Board_test,putPieceOnAnotherOne) {
  EXPECT_EQ(0, createBoard());
  EXPECT_EQ(0, putPiece(1,1,CROSS));
  EXPECT_EQ(1, putPiece(1,1,CROSS));
  EXPECT_EQ(CROSS,getBoardCell(1,1));

  EXPECT_EQ(0, putPiece(2,1,CIRCLE));
  EXPECT_EQ(1, putPiece(2,1,CROSS));
  EXPECT_EQ(CIRCLE,getBoardCell(2,1));
}
