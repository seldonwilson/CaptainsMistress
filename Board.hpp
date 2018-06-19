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
      Board(int _numRows, int _numCols);

      void placeToken(cellState token, int row, int col);
      // overloaded subscript


   private:
      int numRows;
      int numCols;
      vector<vector<cellState>> board;
};



#endif // BOARD_HPP
