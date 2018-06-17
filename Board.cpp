/************************************************************************************
filename: Board.cpp
 authors: Danny & David
************************************************************************************/

#include "Board.hpp"



Board::Board() : Board(7, 6) {}

Board::Board(int _numRows, int _numCols) {
   numRows = _numRows;
   numCols = _numCols;
   board = new char*[numRows];

   for (int row = 0; row < numRows; ++row) {
      board[row] = new char[numCols];
   }

      // Initialize all board spaces to ' '
   for (int row = 0; row < numRows; ++row) {
      for (int col = 0; col < numCols; ++col) {
         board[row][col] = '*';
      }
   }
}


const char** Board::getBoard() const {
   return const_cast<const char**>(board);
}