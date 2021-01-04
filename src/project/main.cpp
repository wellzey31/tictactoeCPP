#include <iostream>
#include "../../include/Board.h"
#include "../../include/Game.h"

int main () {
  char key;
  Game g* = new Game();
  /*Board myBoard;
  myBoard.printBoard();
  myBoard.setMove(1,1,'X');
  myBoard.setMove(2,2,'X');
  myBoard.setMove(3,3,'X');
  myBoard.printBoard();
  std::cout << myBoard.boardFull() << std::endl;
  myBoard.setMove(1,2,'X');
  myBoard.setMove(2,1,'X');
  myBoard.setMove(3,2,'X');
  myBoard.printBoard();
  std::cout << myBoard.boardFull() << std::endl;
  myBoard.setMove(1,3,'X');
  myBoard.setMove(2,3,'X');
  myBoard.setMove(3,1,'X');
  myBoard.printBoard();
  std::cout << myBoard.boardFull() << std::endl;
  */
  do {
  g.run();
  std::cout << "Play again? (y/n): ";
  std::cin >> key;
} while (key)

  return 0;
}
