#include <iostream>

#include "src/factorial.hpp"
#include "src/MonopolyBoard.h"
#include <string>
#include <fstream>
#include <ctime>

// No Benchmarking Needed
// Make it a Generic Linked List

int main() {
  srand(time(nullptr));

  std::string location;
  CircularlyLinkedList<std::string> monopolyBoard;
  std::ifstream FileIn("monopoly_spaces.txt");

  if (!FileIn.is_open()) {
    std::cout << "File could not be opened" << std::endl;
    return 1;
  }

  while (std::getline(FileIn, location)) {
    monopolyBoard.push_back(location);
  }

  FileIn.close();

  std::cout << "\nSetting Up Monopoly Map: \n" << std::endl;
  monopolyBoard.print();
  std::cout << "\nDone!" << std::endl;

  std::cout << "\nHere is your current location: " << std::endl;
  monopolyBoard.step();
  monopolyBoard.currentNode();

  std::cout << "\nLets roll a dice to see where you go next!" << std::endl;

  std::cout << "Rolling: ";
  monopolyBoard.roll();

  std::cout << "\nYou have now moved to: " << std::endl;
  monopolyBoard.currentNode();

  std::cout << "\nLets roll again!" << std::endl;

  std::cout << "Rolling: ";
  monopolyBoard.roll();

  std::cout << "\nYou have now moved to: " << std::endl;
  monopolyBoard.currentNode();

  std::cout << "\nLets roll one last time!" << std::endl;

  std::cout << "Rolling: ";
  monopolyBoard.roll();

  std::cout << "\nYou have now moved to: " << std::endl;
  monopolyBoard.currentNode();

  std::cout << "\nYou go through the rest of the board..." << std::endl;
  for (int i = 0; i < monopolyBoard.size(); i++) {
    monopolyBoard.step();
  }

  std::cout << "\nYou end up at the same location: " << std::endl;
  monopolyBoard.currentNode();

  std::cout << "\nUh Oh. You didn't have enough money to pay rent! "
            << "You have been kicked out and have flipped the gameboard."
            << std::endl;
}
