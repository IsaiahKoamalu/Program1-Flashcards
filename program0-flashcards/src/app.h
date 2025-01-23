#pragma once
#include <vector>
#include "card.h"

class FlashcardsApp{
private:
    std::vector<Card> flashCards;

public:
    FlashcardsApp(std::string fileName);

    void run();
    /*
    This class should have
    - a private member variable for a vector of cards
    - a public constructor with one parameter (filename)
    - a public void function called run()
    */
};
