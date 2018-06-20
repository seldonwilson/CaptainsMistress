
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"

using std::cout;
using std::endl;

int main() {
   Board board;
   board.placeToken(cellState::token1, 0, 0);
   board.placeToken(cellState::token1, 5, 6);
   board.placeToken(cellState::token2, 3, 4);

   TextOutput::printBoard(board);

   return 0;
}
