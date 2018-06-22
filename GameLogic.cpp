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
      int numConsecTokens = 1;
      int rowsChecked = 0;
      int thisRow = row + 1;
      cellState thisToken = brd.getCell(row, col);
         // look down (go at most 3 cells down, but not below row 5)
      while(thisRow <= 5 && rowsChecked < 3) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
            rowsChecked++;
         } else {
            break;
         }
      }

      thisRow = col - 1;
      rowsChecked = 0;
         // look up (go at most 3 cells up, but not above row 0)
      while(thisCol >= 0 && colsChecked < 3) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisCol -= 1;
            colsChecked++;
         } else {
            break;
         }
      }
      return numConsecTokens > 3;
   }

   bool isHorizontalWin(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      int colsChecked = 0;
      int thisCol = col - 1;
      cellState thisToken = brd.getCell(row, col);
         // look left (go at most 3 cells left, but not left of column 0)
      while(thisCol >= 0 && colsChecked < 3) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol -= 1;
            colsChecked++;
         } else {
            break;
         }
      }

      thisCol = col + 1;
      colsChecked = 0;
         // look right (go up to 3 cells right, but not right of column 6)
      while(thisCol <= 6 && colsChecked < 3) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol += 1;
            colsChecked++;
         } else {
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



