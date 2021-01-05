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
  turn++;
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

void Game::playFirst() {
  char c;
  std::cout << "Would you like to play first? (y/n): ";
  std::cin >> cin;
  if (c != 'y' || c != 'Y')  {
    turn++;
  }
}

void Game::computerTurn() {
  int bestX = 0, bestY = 0;
}
