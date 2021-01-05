#ifndef BOARD_H
#define BOARD_H

class Board {
 public:
   Board();
   ~Board();
   void printBoard();
   void setMove(int row, int col, char c);
   bool boardFull();
   bool checkWin();
   void reset();
   void bestMove();
   int getBestX();
   int getBestY();

 private:
   char** b;
   int bestX = 0, bestY = 0;
   int depth = 0;
};
#endif
