/************************************************************************************
filename: GameLogic.cpp
 authors: Coop & Danny
************************************************************************************/

#include "GameLogic.hpp"

// delete later
#include <iostream>

using std::cout;
using std::endl;

namespace GameLogic {

   bool isDiagonalWinNE(const Board & brd, int row, int col) {
      return false;
   }

   bool isDiagonalWinNW(const Board & brd, int row, int col) {
      return false;
   }

   bool isDiagonalWin(const Board & brd, int row, int col) {
      return isDiagonalWinNE(brd, row, col) ||
             isDiagonalWinNW(brd, row, col);
   }

   bool isVerticalWin(const Board & brd, int row, int col) {
      return false;
   }

   bool isHorizontalWin(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      int colsChecked = 0;
      int thisCol = col-1;
      cellState thisToken = brd.getCell(row, col);
         // look left (go up to 3 spaces left while not going left of column 0)
      while(thisCol >= 0 && colsChecked < 3) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol -= 1;
            colsChecked++;
            //cout << "numConsecTokens = " << numConsecTokens << endl;
         } else {
            //cout << "Breaking!" << endl;
            break;
         }
      }

      thisCol = col + 1;
      colsChecked = 0;
         // look right (go up to 3 spaces right while not going right of column 6)
      while(thisCol <= 6 && colsChecked < 3) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol += 1;
            colsChecked++;
            //cout << "numConsecTokens = " << numConsecTokens << endl;
         } else {
            //cout << "Breaking!" << endl;
            break;
         }
      }
      return numConsecTokens > 3;
   }

   bool isWin(const Board & brd, int row, int col) {
      return isHorizontalWin(brd, row, col) ||
             isVerticalWin(brd, row, col) ||
             isDiagonalWin(brd, row, col);
   }
}



// GameLogic Class
// - if a token can go in a given column?
// - bool isColFull(board, col)



