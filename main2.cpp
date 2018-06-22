
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"
#include "GameLogic.hpp"

using std::cout;
using std::endl;

int main() {
   Board board;
   board.placeToken(cellState::token2, 5, 0);
   board.placeToken(cellState::token1, 5, 1);
   board.placeToken(cellState::token1, 5, 2);
   board.placeToken(cellState::token1, 5, 3);

   TextOutput::printBoard(board);

   cout << GameLogic::isWin(board, 5, 3) << endl;

   return 0;
}
