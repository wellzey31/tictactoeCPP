#include <iostream>
#include "../include/Board.h"
#include "../include/Game.h"

Game::Game() {
  b = new Board();
}

Game::~Game() {
  delete board;
}

void Game::run)() {
  while (!b.boardFull()) {
    playerTurn();
  }
}

void Game::playerTurn() {
  int x, y;
  std::cout << "Player's Turn!" << std::endl;
  std::cout << "Enter coordinates for your 'X'(Row Col): ";
  std::cin >> x >> y;
  b.setMove(x,y,'X');
  std::cout << std::endl;
}

bool Game::checkWin() {
  
}
