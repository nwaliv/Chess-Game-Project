#include <iostream>
#include <string>
#include <cmath>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"

// A chess_board_square class. An object of this class must be able to hold a chess piece, and to be able to respond to messages indicating the presence or absence of a chess piece and provide its colour and type, etc.

void chess_board_square::setPieceAndColour(Piece p, Colour c) {
  piece = p;
  colour = c;
}

Piece chess_board_square::getPiece() {
  return piece;
}

Colour chess_board_square::getColour() {
  return colour;
}

void chess_board_square::setEmpty() {
  piece = Empty;
  colour = None;
}

void chess_board_square::setSpace(chess_board_square* space) {
  piece = space->getPiece();
  colour = space->getColour();
}