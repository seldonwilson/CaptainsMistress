/************************************************************************************
filename: Board.cpp
 authors: Danny & David
************************************************************************************/

#include "Board.hpp"


Board::Board() : Board(7, 6) {}

Board::Board(int numRows, int numCols) :
   board(numRows, vector<cellState>(numCols, cellState::blank)) {}

int Board::getNumRows() const {
   return board.size();
}

int Board::getNumCols() const {
   return board.at(0).size();
}

cellState Board::getCell(int row, int col) const {
   return board.at(row).at(col);
}

void Board::placeToken(cellState token, int row, int col) {
   board[row][col] = token;
}
