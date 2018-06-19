/************************************************************************************
filename: Board.hpp
 authors: Danny & David
************************************************************************************/

#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>

enum class cellState {token1, token2, blank};

class Board {
   public:
         // Constructors
      Board();
      Board(int numRows, int numCols);

         // Getters
      int getNumRows() const;
      int getNumCols() const;
      cellState getCell(int row, int col) const;

         // Mutators
      void placeToken(cellState token, int row, int col);

   private:
      std::vector<std::vector<cellState>> board;
};


#endif // BOARD_HPP
