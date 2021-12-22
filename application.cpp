/*An application class. This should have a test method, of course, and should allow interaction with a user through std::cin and std::cout.
The user should be able to create a new chess board with a full set of chess pieces, white and black, in the standard positions. In addition, the user should be able to print out all the pieces and their positions on request and to move a piece from one position to another if permissible. 
For a move to be permissible, the piece must be able to move to the destination position. If the intended destination is occupied, the piece occupying it can be removed ("captured" or "taken") only if it is of the opposite colour and is not the king. 
If the piece can not be removed, the move can not be made. Finally, it must be possible to reinitialise a board (or alternatively, to simply delete it) and start over.
*/

#include <iostream>
#include <cmath>
#include "application.h"
#include "board.h"
#include "chess_board_square.h"

board b;

void application::run() {

  bool newgame = true;
  char response;

  while(newgame) {
    b.init_board();
    while(b.playGame());
    std::cout << "Do you want to play again? Y for yes, anything else for no" << std::endl;
    std::cin >> response;
    if (response != 'Y'&& response !='y')
    newgame = false;
  }
}


void application::test() {
std::cout << "Starting Tests..." << std::endl;
CheckPrintBoard();

std::cout << "Printing Board Test Complete!" << std::endl;

CheckMovePawn();

std::cout << "Movement of Pawn Test Complete!" << std::endl;
}

void application::CheckPrintBoard() {
b.init_board();
b.print_board();

}

void application::CheckMovePawn() {
b.move();
}