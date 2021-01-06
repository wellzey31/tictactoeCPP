/*#include<bits/stdc++.h>
#include "../include/Board.h"

Game::Board() {
  b = new char*[3];
  for(int i = 0; i < 3; i++) {
    b[i] = new char[3];
  }
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b[i][j] = ' ';
    }
  }
}

Board::~Board() {

}

void Game::printBoard() {
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << b[i][j];
      if (j != 2) std::cout << '|';
    }
    if (i != 2) std::cout << std::endl << "_____";
    std::cout << std::endl;
  }
}

void Board::setMove(int row, int col, char c) {
  b[row-1][col-1] = c;
}

bool Board::boardFull() {
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (b[i][j] == ' ') return false;
    }
  }
  return true;
}

bool Game::checkWin() {
  //check rows
  for (int i = 0; i < 3; i++) {
      if (b[i][1] == b[i][0] && b[i][2] == b[i][0] && b[i][0] != ' ') {
      return true;
    }
  }
  //check cols
  for (int i = 0; i < 3; i++) {
      if (b[0][i] == b[1][i] && b[2][i] == b[0][i] && b[0][i] != ' ') {
      return true;
    }
  }
  //check diagonals
  if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] != ' ') {
    return true;
  }
  if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[1][1] != ' ') {
    return true;
  }
  return false;
}

void Board::reset() {
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b[i][j] = ' ';
    }
  }
}*/
