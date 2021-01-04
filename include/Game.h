#ifndef GAME_H
#define GAME_H

class Board;

class Game {
  public:
    Game();
    ~Game();
    void playerTurn();
    void printBoard();
    bool checkWin();
    bool boardNotFull();
    void computerTurn();

  private:
    Board b = nullptr;

};
#endif
