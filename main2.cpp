
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"
#include "GameLogic.hpp"

using std::cout;
using std::endl;

int main() {
   cellState tokenToTest = cellState::token2;

   Board board;
      // test horizontal wins
   board.placeToken(tokenToTest, 5, 0);
   board.placeToken(tokenToTest, 5, 1);
   board.placeToken(tokenToTest, 5, 2);
   board.placeToken(tokenToTest, 5, 3);
   board.placeToken(tokenToTest, 5, 4);
   //board.placeToken(tokenToTest, 5, 5);
   board.placeToken(tokenToTest, 5, 6);

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
   //board1.placeToken(tokenToTest, 0, 0);
   //board1.placeToken(tokenToTest, 1, 0);
   board1.placeToken(tokenToTest, 2, 0);
   board1.placeToken(tokenToTest, 3, 0);
   board1.placeToken(tokenToTest, 4, 0);
   board1.placeToken(tokenToTest, 5, 0);

   cout << endl;
   TextOutput::printBoard(board1);
   cout << endl;

   cout << "0, 0: " << GameLogic::isWin(board1, 0, 0) << endl;
   cout << "1, 0: " << GameLogic::isWin(board1, 1, 0) << endl;
   cout << "2, 0: " << GameLogic::isWin(board1, 2, 0) << endl;
   cout << "3, 0: " << GameLogic::isWin(board1, 3, 0) << endl;
   cout << "4, 0: " << GameLogic::isWin(board1, 4, 0) << endl;
   cout << "5, 0: " << GameLogic::isWin(board1, 5, 0) << endl;

   Board board2;
      // test diagonal wins NE (up and to the right, and down and to the left)
   board2.placeToken(tokenToTest, 5, 0);
   //board2.placeToken(tokenToTest, 5, 1);
   board2.placeToken(tokenToTest, 4, 1);
   board2.placeToken(tokenToTest, 4, 2);
   board2.placeToken(tokenToTest, 3, 3);
   board2.placeToken(tokenToTest, 2, 4);
   //board2.placeToken(tokenToTest, 1, 5);
   //board2.placeToken(tokenToTest, 0, 6);

   cout << endl;
   TextOutput::printBoard(board2);
   cout << endl;

   cout << "5, 0: " << GameLogic::isWin(board2, 5, 0) << endl;
   cout << "5, 1: " << GameLogic::isWin(board2, 5, 1) << endl;
   cout << "4, 1: " << GameLogic::isWin(board2, 4, 1) << endl;
   cout << "4, 2: " << GameLogic::isWin(board2, 4, 2) << endl;
   cout << "3, 3: " << GameLogic::isWin(board2, 3, 3) << endl;



   return 0;
}
