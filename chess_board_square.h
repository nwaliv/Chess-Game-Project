#pragma once
#include <string>

enum Piece { King, Queen, Bishop, Knight, Rook, Pawn, Empty};
enum Colour { White, Black, None};

class chess_board_square {

  Piece piece;
  Colour colour;
  int x, y;

  public:
  
  void setPieceAndColour(Piece, Colour);
  void setSpace(chess_board_square* space);
  void setEmpty();
  Piece getPiece();
  Colour getColour();

  void setX(int ex) {
    x = ex;
  }
  void setY(int why) {
    y = why;
  }
  int getX() {
    return x;
  }
  int getY() {
    return y;
  }

  private:

};