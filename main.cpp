#include <iostream>

#include "src/factorial.hpp"
#include "src/MonopolyBoard.h"
#include <string>
#include <fstream>

// No Benchmarking Needed
// Make it a Generic Linked List

int main() {
  std::string location;
  CircularlyLinkedList<std::string> steps;
  std::ifstream FileIn("monopoly_spaces.txt");

  if (!FileIn.is_open()) {
    std::cout << "File could not be opened" << std::endl;
    return 1;
  }

  while (std::getline(FileIn, location)) {
    steps.push_back(location);
  }

  FileIn.close();
  steps.print();
}
