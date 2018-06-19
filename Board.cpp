/************************************************************************************
filename: Board.cpp
 authors: Danny & David
************************************************************************************/

#include "Board.hpp"



Board::Board() : Board(7, 6) {}

Board::Board(int _numRows, int _numCols) :
   numRows(_numRows),
   numCols(_numCols),
   board(_numRows, vector<cellState>(_numCols, cellState::blank)) {}

