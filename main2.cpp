
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"
#include "GameLogic.hpp"

using std::cout;
using std::endl;

int main() {
   Board board;

   board.placeToken(cellState::token1, 5, 0);
   board.placeToken(cellState::token1, 5, 1);
   board.placeToken(cellState::token1, 5, 2);
   //board.placeToken(cellState::token1, 5, 3);
   board.placeToken(cellState::token1, 5, 4);
   board.placeToken(cellState::token1, 5, 5);
   board.placeToken(cellState::token1, 5, 6);

   TextOutput::printBoard(board);

   cout << "5, 0: " << GameLogic::isWin(board, 5, 0) << endl;
   cout << "5, 1: " << GameLogic::isWin(board, 5, 1) << endl;
   cout << "5, 2: " << GameLogic::isWin(board, 5, 2) << endl;
   cout << "5, 3: " << GameLogic::isWin(board, 5, 3) << endl;
   cout << "5, 4: " << GameLogic::isWin(board, 5, 4) << endl;
   cout << "5, 5: " << GameLogic::isWin(board, 5, 5) << endl;
   cout << "5, 6: " << GameLogic::isWin(board, 5, 6) << endl;

   return 0;
}
