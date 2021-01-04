#ifndef GAME_H
#define GAME_H

class Board;

class Game {
  public:
    Game();
    ~Game();
    void run();
    void playerTurn();
    bool checkWin();
    bool boardNotFull();
    void computerTurn();
    void reset();

  private:
    Board b = nullptr;
    int turn = 0;

};
#endif
