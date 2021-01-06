#ifndef GAME_H
#define GAME_H

struct Move
{
    int row, col;
};

class Game {
  public:
    Game();
    ~Game();
    void run();
    void playerTurn();
    void computerTurn();
    void playFirst();
    Move chooseMove();
    int minimax(int depth, bool isMax);
    void printBoard();
    void setMove(int row, int col, char c);
    bool boardFull();
    bool checkWin();
    void reset();

  private:
    int turn = 0;
    bool win = false;
    char** b;

};
#endif
