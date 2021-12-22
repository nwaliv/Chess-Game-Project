#pragma once
#include "chess_board_square.h"

const int BOARD_SIZE = 8;

class board {
  int piece, colour;
  
  public:
  chess_board_square boardarray[BOARD_SIZE][BOARD_SIZE];
  Colour turn = White;

  void init_board();
  void print_board();
  
  bool playGame();
  bool move();
  bool makeMove(int x1, int y1, int x2, int y2);
  bool movePawn(chess_board_square* thisPawn, chess_board_square* thatSpace);
  bool moveRook(chess_board_square* thisRook, chess_board_square* thatSpace);
  bool moveBishop(chess_board_square* thisBishop, chess_board_square* thatSpace);
  bool moveQueen(chess_board_square* thisQueen, chess_board_square* thatSpace);
  bool moveKnight(chess_board_square* thisKnight, chess_board_square* thatSpace);
  bool moveKing(chess_board_square* thisKing, chess_board_square* thatSpace);
  
  chess_board_square* getSquare(int x, int y) {
    return &boardarray[x][y];
  }

  private:
  
};