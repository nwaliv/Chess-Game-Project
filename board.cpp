#include <iostream>
#include <string>
#include <cmath>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"

/* A board class. This should be able to represent a chess board. A board object should incorporate a two-dimensional array of chess_board_square objects, each of which can possibly hold a chess piece. A board object must be able to respond to the messages sent to it by the application object, as listed above. */

//const int BOARD_SIZE = 8;


void board::print_board() {
	
  std::cout << " y: 0  1  2  3  4  5  6  7 " << std::endl << " x:" << std::endl;

	for(int i = 0; i < BOARD_SIZE; i++) {

    std::cout << " " << i << " ";
    for (int j = 0; j < BOARD_SIZE; j++) {

      piece = boardarray[i][j].getPiece();
      colour = boardarray[i][j].getColour();
    

      switch (piece) {
        case King: 
        if (colour == White) 
          std::cout << " K ";
        else if (colour == Black)
          std:: cout << " k ";
        break;

        case Queen:
        if (colour == White)
          std::cout << " Q ";
        else if (colour == Black)
          std::cout << " q ";
        break;

        case Bishop:
        if (colour == White)
          std::cout << " B ";
        else if (colour == Black)
          std::cout << " b ";
        break;

        case Knight:
        if (colour == White)
          std::cout << " H ";
        else if (colour == Black)
          std::cout << " h ";
        break; 

        case Rook:
        if (colour == White)
          std::cout << " R ";
        else if (colour == Black)
          std::cout << " r ";
        break;

        case Pawn:
        if (colour == White)
          std::cout << " P ";
        else if (colour == Black)
          std::cout << " p ";
        break;

        case Empty:
          std::cout << "  " << "\21" << " ";
        break;

        default:std::cout << "XXX";
        break; 
      }
    }
  std::cout << std::endl;
	}
}

void board::init_board() {
  boardarray[0][0].setPieceAndColour(Rook, White);
  boardarray[1][0].setPieceAndColour(Knight, White);
  boardarray[2][0].setPieceAndColour(Bishop, White);
  boardarray[3][0].setPieceAndColour(Queen, White);
  boardarray[4][0].setPieceAndColour(King, White);
  boardarray[5][0].setPieceAndColour(Bishop, White);
  boardarray[6][0].setPieceAndColour(Knight, White);
  boardarray[7][0].setPieceAndColour(Rook, White);

  boardarray[0][7].setPieceAndColour(Rook, Black);
  boardarray[1][7].setPieceAndColour(Knight, Black);
  boardarray[2][7].setPieceAndColour(Bishop, Black);
  boardarray[3][7].setPieceAndColour(Queen, Black);
  boardarray[4][7].setPieceAndColour(King, Black);
  boardarray[5][7].setPieceAndColour(Bishop, Black);
  boardarray[6][7].setPieceAndColour(Knight, Black);
  boardarray[7][7].setPieceAndColour(Rook, Black);

  for (int i = 0; i < BOARD_SIZE; i++) {
    boardarray[i][1].setPieceAndColour(Pawn, White);
    boardarray[i][6].setPieceAndColour(Pawn, Black);
    //boardarray[i][1].getSpace(i, 1);
  }

  for (int j = 2; j < BOARD_SIZE-2; j++) {
    for (int i = 0; i < BOARD_SIZE; i++) {
      boardarray[i][j].setPieceAndColour(Empty, None);
    }
  }

  for (int i = 0; i < BOARD_SIZE; i++)
    for (int j = 0; j < BOARD_SIZE; j++) {
      boardarray[i][j].setX(i);
      boardarray[i][j].setY(j);
    }
  
}

bool board::makeMove(int x1, int y1, int x2, int y2) {

  if (x1 < 0 || y1 > 7 || x2 < 0 || y2 > 8) {
    std::cout << "Incorrect input. Try again " << std::endl;
  }
  chess_board_square* src = getSquare(x1, y1);
  chess_board_square* dest = getSquare (x2, y2);

  if (src->getColour() == dest->getColour() && dest->getColour() != None)
  {
    std::cout << "You cannot land on your own piece. Try again" << std::endl;
    return false;
  }

  switch (src->getPiece())
  {
    case King:
      return moveKing(src, dest);
    break;
    case Queen:
      return moveQueen(src, dest);
    break;
    case Knight:
      return moveKnight(src, dest);
    break;
    case Bishop:
      return moveBishop(src, dest);
    break;
    case Rook:
      return moveRook(src, dest);
    break;
    case Pawn:
      return movePawn(src, dest);
    break;
    case Empty:
      std::cout << "You do not have a piece there. Try again " << std::endl;
      return false;
    break;
      default:std::cerr << "A problem ocurred" << std::endl;
    break;
  }
  return false;
}

bool board::movePawn(chess_board_square* thisPawn, chess_board_square* thatSpace) {
  int pawnX = thisPawn->getX();
  int pawnY = thisPawn->getY();
  int spaceX = thatSpace->getX();
  int spaceY = thatSpace->getY();
  //std::cout << pawnX << pawnY;
  //std::cout << spaceX << spaceY;

  //boardarray[newx][newy] = boardarray[oldx][newx]

  if (thisPawn->getColour() == White) {

  
    if (pawnX == spaceX && spaceY == pawnY + 1 && thatSpace->getColour() == None) {
      thatSpace->setSpace(thisPawn);
      thisPawn->setEmpty();
      return true;
 }
    else if ((pawnX == spaceX + 1 || pawnX == spaceX - 1) && spaceY == pawnY + 1 && thatSpace->getColour() == Black) {
      thatSpace->setSpace(thisPawn);
      thisPawn->setEmpty();
      return true;
    }
    else return false;
  }
  else if (thisPawn->getColour() == Black) {
    if (pawnX == spaceX && spaceY == pawnY - 1 && thatSpace->getColour() == None) {
      thatSpace->setSpace(thisPawn);
      thisPawn->setEmpty();
      return true;
    }
    else if ((pawnX == spaceX + 1 || pawnX == spaceX - 1) && spaceY == pawnY - 1 && thatSpace->getColour() == White) {
      thatSpace->setSpace(thisPawn);
      thisPawn->setEmpty();
      return true;
    }
    else return false;
  }
  else return false;
}
bool board::moveRook(chess_board_square* thisRook, chess_board_square* thatSpace) {
  int rookX = thisRook->getX();
  int rookY = thisRook->getY();
  int spaceX = thatSpace->getX();
  int spaceY = thatSpace->getY();
  bool invalid = false;

  if (rookX != spaceX || rookY != spaceY) {
    if (rookX == spaceX) {
      int increment1 = (spaceY - rookY) / (abs(spaceY - rookY));
      for (int i = rookY+increment1; i != spaceY; i+=increment1) {
        if (boardarray[spaceX][i].getColour() != None)
          return false;
        
      }
    }

    else if (rookY == spaceY) {
      int increment2 = (spaceX - rookX) / (abs(spaceX - rookX));
      for (int i = rookX+increment2; i != spaceY; i+=increment2) {
        if (boardarray[i][spaceY].getColour() != None)
          return false;
        
      }
    }
    else return false;
  }

  if (invalid == false) {
    thatSpace->setSpace(thisRook);
    thisRook->setEmpty();
    return true;
  }
  else {
    std::cout << "A problem has occured in moving the rook" << std::endl;
    return false;
  }
}

bool board::moveBishop(chess_board_square* thisBishop, chess_board_square* thatSpace) {
  int bishopX = thisBishop->getX();
  int bishopY = thisBishop->getY();
  int spaceX = thatSpace->getX();
  int spaceY = thatSpace->getY();
  bool invalid = false;

  if (abs(bishopX - spaceX) == abs(bishopY - spaceY)) {

    int increment1 = (spaceX - bishopX)/(abs(spaceX - bishopX));
    int increment2 = (spaceY - bishopY)/(abs(spaceY - bishopY));

    for (int i = 1; i < abs(bishopX - spaceX); i++) {
      if (boardarray[bishopX + (increment1 * i)][bishopY + (increment2 * i)].getColour() != None)
        return false;
    }
  }
  else return false;

  if (invalid == false) {
    thatSpace->setSpace(thisBishop);
    thisBishop->setEmpty();
    return true;
  }
  else {
    std::cout << "A problem has occured in moving the bishop" << std::endl;
    return false;
  }
}

bool board::moveQueen(chess_board_square* thisQueen, chess_board_square* thatSpace) {
  int queenX = thisQueen->getX();
  int queenY = thisQueen->getY();
  int spaceX = thatSpace->getX();
  int spaceY = thatSpace->getY();
  bool invalid = false;

  if (queenX != spaceX || queenY != spaceY) {
    if (queenX == spaceX) {
      int increment1 = (spaceY - queenY) / (abs(spaceY - queenY));
      for (int i = queenY+increment1; i != spaceY; i+=increment1) {
        if (boardarray[spaceX][i].getColour() != None)
          return false;
        
      }
    }

    else if (queenY == spaceY) {
      int increment2 = (spaceX - queenX) / (abs(spaceX - queenX));
      for (int i = queenX+increment2; i != spaceY; i+=increment2) {
        if (boardarray[i][spaceY].getColour() != None)
          return false;
        
      }
    }
    else if (abs(queenX - spaceX) == abs(queenY - spaceY)) {

    int increment1 = (spaceX - queenX)/(abs(spaceX - queenX));
    int increment2 = (spaceY - queenY)/(abs(spaceY - queenY));

    for (int i = 1; i < abs(queenX - spaceX); i++) {
      if (boardarray[queenX + (increment1 * i)][queenY + (increment2 * i)].getColour() != None)
        return false;
    }
    }
  }
  else return false;

  if (invalid == false) {
    thatSpace->setSpace(thisQueen);
    thisQueen->setEmpty();
    return true;
  }
  else {
    std::cout << "A problem has occured in moving the queen" << std::endl;
    return false;
  }
}

bool board::moveKnight(chess_board_square* thisKnight, chess_board_square* thatSpace) {
  int knightX = thisKnight->getX();
  int knightY = thisKnight->getY();
  int spaceX = thatSpace->getX();
  int spaceY = thatSpace->getY();
  
  if ((abs(knightX - spaceX) == 2 && abs(knightY - spaceY) == 1) || (abs(knightX - spaceX) == 1 && abs(knightY - spaceY) == 2)) {
    thatSpace->setSpace(thisKnight);
    thisKnight->setEmpty();
    return true;
  }
  else {
    std::cout << "A problem ocurred in moving the knight " << std::endl;
    return false;
  }
}

bool board::moveKing(chess_board_square* thisKing, chess_board_square* thatSpace) {
  if (abs(thatSpace->getX() - thisKing->getX()) == 1)
		if (abs(thatSpace->getY() - thisKing->getY()) == 1)
		{
			thatSpace->setSpace(thisKing);
			thisKing->setEmpty();
			return true;
		}
		else return false;

	else return false;
}

bool board::move() {
  int x1, x2, y1, y2;
  bool stop = false;
  char input;
  int counter = 1;

  while (!stop) {
    if (turn == White)
      std::cout << "It is Player White's Turn" << std::endl;
    else
      std::cout << "It is Player Black's Turn" << std::endl;

    std::cout << "Which piece do you want to move? " << std::endl;

    std::cin >> x1 >> y1;

    std::cout << "Where do you want to move it to? " << std::endl;

    std::cin >> x2 >> y2;

    if (getSquare(x1, y1)->getColour() == turn) {
      if (makeMove(x1, y1, x2, y2) == false)
        std::cout << "Invalid move. Try again" << std::endl;
      else
        stop = true;
    }
    else
      std::cout << "Not your piece. Try again" << std::endl;
    
    
    counter++;
    std::cout << "To reprint the board, please press 'r'. To quit the current game, please press 'q' " << std::endl;
  
    std::cin >> input;
    if (input == 'r' || input == 'R')
      std::cout << "It is now turn No. " << counter << std::endl;
    else if (input == 'q' || input == 'Q')
      return false;
    else
      std::cout << "It is now turn No. " << counter << std::endl;
  }
  

  if (getSquare(x2, y2)->getPiece() == King)
		if (getSquare(x1, y1)->getColour() == White)
		{
			std::cout << "WHITE WINS" << std::endl;
			return false;
		}
		else {
			std::cout << "BLACK WINS" << std::endl;
			return false;
		}

  else if (turn == Black)
    turn = White;
    else
      turn = Black;

  return true;
}

bool board::playGame() {
  print_board();

  return move();
}