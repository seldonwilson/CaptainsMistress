/************************************************************************************
filename: Board.hpp
 authors: Danny & David
************************************************************************************/

#ifndef BOARD_HPP_
#define BOARD_HPP_

class Board {
   public:
      Board();
      Board(int numRows, int numCols);

      void placeToken(int row, int col);
      const char** getBoard();


   private:
      char** board;
      int numRows;
      int numCols;
};



#endif // BOARD_HPP