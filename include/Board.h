#ifndef GAME_H
#define GAME_H

class Board {
 public:
   Board();
   ~Board();
   void printBoard();
   void setMove(int row, int col, char c);
   bool boardFull();
   bool checkwin();
   void reset();

 private:
   char** b;
   char win = '';
};
#endif
