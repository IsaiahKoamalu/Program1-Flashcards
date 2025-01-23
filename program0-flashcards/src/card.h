#pragma once
#include <string>

class Card
{
private:
    std::string front;
    std::string back;

public:
    Card(std::string f, std::string b) : front(f), back(b){}

    std::string getFront();

    std::string getBack();
    /*

    This class should have
    - private member variables for the front and back side of the card
    - a public constructor with two parameters (front and back) which sets the member variables
    - public getters for front and back
    */
};