#include "board.h"
#include "gameManager_test.c"

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
