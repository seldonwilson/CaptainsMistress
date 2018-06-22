/************************************************************************************
filename: GameLogic.cpp
 authors: Coop & Danny
************************************************************************************/

#include "GameLogic.hpp"

/** Danny's suggesstions **
- Using Board.getNumRows() and Board.getNumCols() would make this code more generic
  and work with different sized board instead of hardcoding values like 5 and 6.
- Coop's response: I agree - I updated the methods per your suggestions

- I still don't understand why we need rowsChecked and numConsecTokens. Don't we want
  to end the checks right when numConsecTokens is 4? 
- Coop's thoughts about why he initially included rowsChecked: 
      Do we want to keep checking for wins all the way to the edge of the 2D array? Or
      do we only want to check for wins resulting from placing this token? If we don't
      care about checking (in any/all of the directions - horiz, vert, diag) all the way
      to the edge, then it seems like we don't need rowsChecked/colsChecked, only 
      numConsecTokens
- Duh... disregard above comment. Yes, you're right Danny. For some reason I was thinking 
  we were still checking to the edge, but we'll only keep checking (stay in the while loop)
  while we continue to get the same consecutive tokens, and we only ever need 4 of these. So
  I think you're right. We'll test when we meet next

**/


// delete later
#include <iostream>

using std::cout;
using std::endl;

namespace GameLogic {
      // checks for wins on the diagonal up and to the right, and down and to the left
   bool isDiagonalWinNE(const Board & brd, int row, int col) {
      int numConsecTokens = 1;
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look up, and to the right (check at most 3 cells, 
         // but not above row 0 or right of rightmost column)
      int thisRow = row - 1;
      int thisCol = col + 1;
      int numCellsChecked = 0;
      while(thisRow >= 0 && thisCol < brd.getNumCols() && numCellsChecked < 3) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow -= 1;
            thisCol += 1;
            numCellsChecked++;
         } else {
            break;
         }
      }

         // look down, and to the left (check at most 3 cells, 
         // but not below last/bottom row or left of column 0)
      thisRow = row + 1;
      thisCol = col - 1;
      numCellsChecked = 0;
      while(thisRow < brd.getNumRows() && thisCol >= 0 && numCellsChecked < 3) {
         if(brd.getCell(thisRow, thisCol) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
            thisCol -= 1;
            numCellsChecked++;
         } else {
            break;
         }
      }

      return numConsecTokens > 3;
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
      cellState thisToken = brd.getCell(row, col);
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
         // look down (go at most 3 cells down, but not below last/bottom row)
      int thisRow = row + 1;
      int rowsChecked = 0;
      while(thisRow < brd.getNumRows()  && rowsChecked < 3) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisRow += 1;
            rowsChecked++;
         } else {
            break;
         }
      }

         // look up (go at most 3 cells up, but not above row 0)
      thisRow = row - 1;
      rowsChecked = 0;
      while(thisRow >= 0 && rowsChecked < 3) {
         if(brd.getCell(thisRow, col) == thisToken) {
            numConsecTokens++;
            thisRow -= 1;
            rowsChecked++;
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
         // after testing, remove line below
      if(thisToken == cellState::blank) return false;
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
         // look right (go up to 3 cells right, but not right of rightmost column)
      while(thisCol < brd.getNumCols() && colsChecked < 3) {
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
      // - bool isColFull(board, col)
   bool isColFull(const Board & brd, int col) {
      for(int i = 0; i < brd.getNumRows(); i++) {
         if(brd.getCell(i, col) == cellState::blank) {
            return false;
         }
      }
      return true;
   }


} // end of namespace

