/************************************************************************************
filename: Board.hpp
 authors: Danny & David
************************************************************************************/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>

using std::vector;

enum class cellState {token1, token2, blank};

class Board {
   public:
      Board();
      Board(int numRows, int numCols);

      void placeToken(cellState token, int row, int col);
      int getNumRows() const;
      int getNumCols() const;
      cellState getCell(int row, int col) const;

   private:
      vector<vector<cellState>> board;
};


#endif // BOARD_HPP
