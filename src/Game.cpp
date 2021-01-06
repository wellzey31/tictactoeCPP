#include<bits/stdc++.h>
#include "../include/Game.h"

Game::Game() {
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

Game::~Game() {
  delete b;
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

void Game::setMove(int row, int col, char c) {
  b[row-1][col-1] = c;
}

bool Game::boardFull() {
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

void Game::run() {
  do {
    printBoard();
    std::cout << turn << std::endl;
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
    turn++;
  } while (!boardFull());
  if(!win) std::cout << "Tie game." << std::endl;
  if(win) printBoard();
}

void Game::playerTurn() {
  int x, y;
  std::cout << "Player's Turn!" << std::endl;
  std::cout << "Enter coordinates for your 'X'(Row Col): ";
  std::cin >> x >> y;
  setMove(x,y,'X');
  std::cout << std::endl;
}

void Game::reset() {
  turn = 0;
  win = false;
  for(int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b[i][j] = ' ';
    }
  }
}

void Game::playFirst() {
  char c;
  std::cout << "Would you like to play first? (y/n): ";
  std::cin >> c;
  if (!(c == 'y' || c == 'Y'))  {
    std::cout << "what" << std::endl;
    turn++;
  }
}

void Game::computerTurn() {
  Move cpuMove = chooseMove();
  setMove(cpuMove.row, cpuMove.col, 'O');
}

Move Game::chooseMove() {
  int bestVal = -1000;
  Move bestMove;
  bestMove.row = -1;
  bestMove.col = -1;

  //traverse board for open positions
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      //check for empty positions
      if (b[i][j] == ' ') {
        b[i][j] = 'O';
        int moveVal = minimax(0, false);

        //undo move
        b[i][j] = ' ';

        //if the value is max then this is the best move
        if (moveVal > bestVal) {
          bestMove.row = i;
          bestMove.col = j;
          bestVal = moveVal;
        }
      }
    }
  }
  return bestMove;
}

int Game::minimax(int depth, bool isMax) {
  //cpu win condition
  if (!isMax && checkWin()) {
    return 10;
  //human win check
  } else if (isMax && checkWin()) {
    return -10;
  //tie check
} else if (boardFull()) {
    return 0;
  }
  if (isMax) {
    int best = -100;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (b[i][j] == ' ') {
          //make move
          b[i][j] = 'O';
          //compute max
          best = std::max(best, minimax(depth+1, !isMax));
          //undo move
          b[i][j] = ' ';
        }
      }
    }
    return best;
  } else {
    int best = 100;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (b[i][j] == ' ') {
          //make move
          b[i][j] = 'X';
          //compute max
          best = std::min(best, minimax(depth+1, !isMax));
          //undo move
          b[i][j] = ' ';
        }
      }
    }
    return best;
  }
}
