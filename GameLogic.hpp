/************************************************************************************
filename: GameLogic.hpp
 authors: Coop & Danny
************************************************************************************/

#ifndef GAME_LOGIC_HPP_
#define GAME_LOGIC_HPP_

#include "Board.hpp"


namespace GameLogic {

      // did a given move win the game?
   bool isWin(const Board & brd, int row, int col);

   bool isColFull(const Board & brd, int col);

}


#endif // GAME_LOGIC_HPP_





// GameLogic Class
// - if a token can go in a given column?
// - bool isColFull(board, col)



