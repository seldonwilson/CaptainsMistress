/************************************************************************************
filename: Board.hpp
 authors: Danny & David
************************************************************************************/

#ifndef BOARD_HPP_
#define BOARD_HPP_

enum class cellState {X, O, Blank};

class Board {
   public:
      Board();
      Board(int _numRows, int _numCols);

      void placeToken(cellState token, int row, int col);
      const char** getBoard() const;
      // overloaded subscript


   private:
      char** board;
      int numRows;
      int numCols;
};



#endif // BOARD_HPP
