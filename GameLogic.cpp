/************************************************************************************
filename: GameLogic.cpp
 authors: Coop & Danny
************************************************************************************/

#include "GameLogic.hpp"

namespace GameLogic {

      // checks for wins on the diagonal up and to the right, and down and to the left
   bool isDiagonalWinNE(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look up, and to the right (but not above row 0 or right of rightmost column)
      int thisRow = row - 1;
      int thisCol = col + 1;
      while(thisRow >= 0 && thisCol < brd.getNumCols() && numConsecTokens < 4) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow -= 1;
            thisCol += 1;
         } else {
            break;
         }
      }
         // look down, and to the left (but not below last/bottom row or left of column 0)
      thisRow = row + 1;
      thisCol = col - 1;
      while(thisRow < brd.getNumRows() && thisCol >= 0 && numConsecTokens < 4) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
            thisCol -= 1;
         } else {
            break;
         }
      }
      return numConsecTokens > 3;
   }

      // checks for wins on the diagonal up and to the left, and down and to the right
   bool isDiagonalWinNW(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look up, and to the left (but not above row 0 or left of column 0)
      int thisRow = row - 1;
      int thisCol = col - 1;
      while(thisRow >= 0 && thisCol >= 0 && numConsecTokens < 4) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow -= 1;
            thisCol -= 1;
         } else {
            break;
         }
      }
         // look down, and to the right (not below last/bottom row or right of rightmost col)
      thisRow = row + 1;
      thisCol = col + 1;
      while(thisRow < brd.getNumRows() && thisCol < brd.getNumCols() && numConsecTokens < 4) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
            thisCol += 1;
         } else {
            break;
         }
      }
      return numConsecTokens > 3;
   }

   bool isDiagonalWin(const Board & brd, int row, int col) {
      return isDiagonalWinNE(brd, row, col) ||
             isDiagonalWinNW(brd, row, col);
   }

   bool isVerticalWin(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look down (but not below last/bottom row)
      int thisRow = row + 1;
      while(thisRow < brd.getNumRows() && numConsecTokens < 4) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
         } else {
            break;
         }
      }
         // look up (but not above row 0)
      thisRow = row - 1;
      while(thisRow >= 0 && numConsecTokens < 4) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisRow -= 1;
         } else {
            break;
         }
      }
      return numConsecTokens > 3;
   }

   bool isHorizontalWin(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look left (but not left of column 0)
      int thisCol = col - 1;
      while(thisCol >= 0 && numConsecTokens < 4) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol -= 1;
         } else {
            break;
         }
      }
         // look right (but not right of rightmost column)
      thisCol = col + 1;
      while(thisCol < brd.getNumCols() && numConsecTokens < 4) {
         if(brd.getCell(row, thisCol) == thisToken) {
            numConsecTokens++;
            thisCol += 1;
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

      // assumes a column that is in range
   bool isColFull(const Board & brd, int col) {
      for(int i = 0; i < brd.getNumRows(); i++) {
         if(brd.getCell(i, col) == cellState::blank) {
            return false;
         }
      }
      return true;
   }

      // assumes a valid column 
   void placeToken(Board & brd, cellState currToken, int col) {
      int rowIndex = brd.getNumRows() - 1; 
      while(brd.getCell(rowIndex, col) != cellState::blank) {
         rowIndex--;
      }
      brd.placeToken(currToken, rowIndex, col);
   }
} // end of GameLogic namespace
