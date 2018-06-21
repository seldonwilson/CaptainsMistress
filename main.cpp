
#include <iostream>
#include "Board.hpp"
#include "TextOutput.hpp"
#include "InputString.hpp"

using std::cout;
using std::endl;

int main() {
   Board board;
   board.placeToken(cellState::token1, 0, 0);
   board.placeToken(cellState::token1, 5, 6);
   board.placeToken(cellState::token2, 3, 4);

   TextOutput::printBoard(board);

   //string myTestString = "1234";
   InputString myInputString("1?34");
   bool res = myInputString.isIntInRange(1, 2000);

   cout << "Is an int in range: " << res << endl;

   int myInt = myInputString.asInt();

   cout << "As an int: " << myInt << endl;



   return 0;
}
