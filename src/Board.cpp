#include <iostream>
#include "../include/Board.h"

Board::Board() {
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

void Board::printBoard() {
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

bool Board::checkWin() {
  char first = '';
  //check rows
  for (int i = 0; i < 3; i++) {
    char first = b[i][0];
    if (b[i][1] && b[i][2]) return true;
  }
  //check cols
  for (int i = 0; i < 3; i++) {
    char first = b[0][i];
    if (b[1][i] && b[2][i]) return true;
  }
  //check diagonals
  if ()
}
