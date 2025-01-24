#include "app.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

//Initiallize Vector of Card objects
FlashcardsApp::FlashcardsApp(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Problem Opening File->" << fileName << std::endl; //Error Handling
    }

    std::string current;
    std::string next;

    while (std::getline(file, current, '\t')) {
        std::getline(file, next);
        Card card(current, next);
        flashCards.push_back(card);
    }
}


//Function that contains the main loop logic for the program
void FlashcardsApp::run() {
    srand(time(0)); //seed the random integer generator

    char input;

    while (input != 113) { //Loop will run while the value of input char is not equal to the ASCII value of q(quit).

        int randomElement = rand() % flashCards.size() + 0; //generate random integer in range of 0 -> Size of Cards vector.

        //Set temporary front and back strings to the current Card using the previously generated random number.
        std::string currentFront = flashCards[randomElement].getFront();
        std::string currentBack = flashCards[randomElement].getBack();

        std::cout << "\nFront: " << currentFront << std::endl;
        std::cin.get(input);
        if (input == 10)
            std::cout << "Back: " << currentBack << std::endl;
        std::cin.get(input);
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
