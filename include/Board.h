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

 private:
   char** b;
};
#endif
