#include "app.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

FlashcardsApp::FlashcardsApp(std::string fileName) {
  std::ifstream file(fileName);
  if(!file.is_open()) {
    std::cerr << "Error: Problem Opening File->" << fileName << std::endl;//Error Handling
  }

  std::string current;
  std::string next;

  while(std::getline(file, current, '\t')) {
    std::getline(file, next);
    Card card(current, next);
    flashCards.push_back(card);
  }
}

void FlashcardsApp::run() {
  srand(time(0));

  std::string input;

  bool running = true;
  while(running) {
    int randomElement = rand() % flashCards.size() + 0;

    std::string currentFront = flashCards[randomElement].getFront();
    std::string currentBack = flashCards[randomElement].getBack();

    std::cout << "\nFront: " << currentFront << std::endl;
    std::cin >> input;
    if(input == "q")
      running = false;
    else
      std::cout << "Back: " << currentBack << std::endl;
      std::cin >> input;

  }
}
/*
Implement the Flashcards App constructor.
The constructor should read the TSV file passed to the constructor and store it in a vector of Card

Implement Flashcards App's run().
This function enters a loop. At each iteration,
- select a random card from the vector of cards
- display the front side to the user
- prompt the user to press enter
- display the back side to the user
- prompt the user to press enter to show another card,
  or type "quit" to quit the program
*/
