#include <iostream>
#include "../include/Board.h"
#include "../include/Game.h"

Game::Game() {
  b = new Board();
}

Game::~Game() {
  delete b;
}

void Game::run() {
  do {
    b -> printBoard();
    if(turn % 2 == 0) {
      playerTurn();
      if (checkWin()) {
        std::cout << "You win!" << std::endl;
        win = true;
        break;
      }
    } else {
      computerTurn();
      if (checkWin()) {
        std::cout << "Computer wins." << std::endl;
        win = true;
        break;
      }
    }
  } while (!b->boardFull());
  if(!win) std::cout << "Tie game." << std::endl;
  if(win) b -> printBoard();
}

void Game::playerTurn() {
  int x, y;
  std::cout << "Player's Turn!" << std::endl;
  std::cout << "Enter coordinates for your 'X'(Row Col): ";
  std::cin >> x >> y;
  b->setMove(x,y,'X');
  std::cout << std::endl;
}

bool Game::checkWin() {
  return b->checkWin();
}

void Game::reset() {
  turn = 0;
  win = false;
  b -> reset();
}
