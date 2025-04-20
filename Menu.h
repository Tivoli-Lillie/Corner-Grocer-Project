#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "ProductInventory.h"

std::string titleCaseInput(std::string input); // Function to convert input to title case,
                                             // This is used by classes other than just Menu

class Menu{
private:
    std::vector<std::string> menuOptions; // Vector of menu options

public:
    Menu(); // Constructor

    void displayMenu() const; // Function to display menu

    int getUserInput(int userInput); // function to get user input

    void processUserInput(int userInput, ProductInventory& inventory); // Function to process user input

};
#endif 