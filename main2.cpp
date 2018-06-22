
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"
#include "GameLogic.hpp"

using std::cout;
using std::endl;

int main() {
   Board board;
      // test horizontal wins
   board.placeToken(cellState::token1, 5, 0);
   board.placeToken(cellState::token1, 5, 1);
   board.placeToken(cellState::token1, 5, 2);
   board.placeToken(cellState::token1, 5, 3);
   //board.placeToken(cellState::token1, 5, 4);
   board.placeToken(cellState::token1, 5, 5);
   board.placeToken(cellState::token1, 5, 6);

   cout << endl;
   TextOutput::printBoard(board);
   cout << endl;

   cout << "5, 0: " << GameLogic::isWin(board, 5, 0) << endl;
   cout << "5, 1: " << GameLogic::isWin(board, 5, 1) << endl;
   cout << "5, 2: " << GameLogic::isWin(board, 5, 2) << endl;
   cout << "5, 3: " << GameLogic::isWin(board, 5, 3) << endl;
   cout << "5, 4: " << GameLogic::isWin(board, 5, 4) << endl;
   cout << "5, 5: " << GameLogic::isWin(board, 5, 5) << endl;
   cout << "5, 6: " << GameLogic::isWin(board, 5, 6) << endl;

   Board board1;
      // test vertical wins
   board1.placeToken(cellState::token1, 0, 0);
   board1.placeToken(cellState::token1, 1, 0);
   board1.placeToken(cellState::token1, 2, 0);
   board1.placeToken(cellState::token1, 3, 0);
   //board1.placeToken(cellState::token1, 4, 0);
   board1.placeToken(cellState::token1, 5, 0);

   cout << endl;
   TextOutput::printBoard(board1);
   cout << endl;

   cout << "0, 0: " << GameLogic::isWin(board, 5, 0) << endl;
   cout << "1, 0: " << GameLogic::isWin(board, 5, 1) << endl;
   cout << "2, 0: " << GameLogic::isWin(board, 5, 2) << endl;
   cout << "3, 0: " << GameLogic::isWin(board, 5, 3) << endl;
   cout << "4, 0: " << GameLogic::isWin(board, 5, 4) << endl;
   cout << "5, 0: " << GameLogic::isWin(board, 5, 5) << endl;

   return 0;
}
