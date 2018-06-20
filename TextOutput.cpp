/************************************************************************************
filename: TextOutput.cpp
 authors: Danny & David
************************************************************************************/

#include "TextOutput.hpp"
#include <iostream>

using std::cout;
using std::endl;

void TextOutput::printBoard(const Board & board) {
   int numRows = board.getNumRows();
   int numCols = board.getNumCols();

   for(int row = 0; row < numRows; ++row) {
      for(int col = 0; col < numCols; ++col) {
         cellState currCell = board.getCell(row, col);
         char cellView;
         if(currCell == cellState::token1) {
            cellView = 'X';
         }
         else if(currCell == cellState::token2) {
            cellView = 'O';
         }
         else {
            cellView = '.';
         }
         cout << cellView << " ";
      }
      cout << endl;
   }
}
