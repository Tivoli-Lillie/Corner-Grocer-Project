#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>

#include "Menu.h"
#include "ProductInventory.h"

Menu::Menu() : menuOptions({ // Constructor
    "[1] Find the frequency of an product",
    "[2] Print all products and their frequencies",
    "[3] View a histogram of all product frequencies",
    "[4] Exit"
}) {}

void Menu::displayMenu() const { // Function to display menu
    for (const std::string& option : menuOptions) { // Print each menu option from list, on a new line
        std::cout << option << std::endl;
    }
    std::cout << std::endl;
}

int Menu::getUserInput(int userInput) { // function to get user input
    
    do {
        std::cout << "Enter menu option: "; // Prompt for user input

        try { // try for valid input
            std::cin >> userInput; // Get user input

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear buffer

            // Get rid of bad data on buffer
            if (std::cin.fail()) { // If input is invalid
                std::cin.clear(); // clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
                throw std::invalid_argument("Error: Invalid input");
                
            }
            if (userInput < 1 || userInput > 4) { // If input is out of range
                throw std::out_of_range("Error: Options are 1-4");
            }
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }

    } while (std::cin.fail() || userInput < 1 || userInput > 4); // If input is invalid

    return userInput; // Return user input
}

void Menu::processUserInput(int userInput, ProductInventory& inventory) { // Function to process user input
    switch (userInput) { 
        case 1: { // Find frequency of product
            std::string productName; // Variable to hold product name
            std::cout << std::endl; 

            std::cout << "Enter a product name: "; // Prompt for product name
            std::getline(std::cin, productName); // Get product name
            
            std::cout << std::endl;

            // Convert input to lowercase
            //std::cout << "Converting input to correct format..."; // For debugging
            std::string titleCaseName = titleCaseInput(productName);
            //std::cout << titleCaseName << std::endl;
            
            if (inventory.checkForProduct(titleCaseName)) { // compare input and map key as same case
                std::cout <<  titleCaseName << " " << inventory.findProductfrequency(titleCaseName) << std::endl;
                
            } else { // Product not found in inventory
                    std::cout << "There's no record of " << productName << " being purchased." << std::endl;
            }
            std::cout << std::endl; 
            break;
        }
        case 2: { // Print all products and frequencies
            inventory.printAllFrequency("list"); // Print all products and frequencies
            std::cout << std::endl;
            break;
        }
        case 3: {// View histogram of all product frequencies
            inventory.printAllFrequency("histogram"); // Print histogram
            break;
        }
        case 4: { // Exit
            std::cout << std::endl; 
            std::cout << "Exiting program..." << std::endl;
            exit(0); // Exit program
        }
        default: {// If invalid input
            std::cout << std::endl; 
            std::cout << "Please enter a valid menu option (1-4)" << std::endl; // Prompt for valid input
            break;
        }
    }
}

std::string titleCaseInput(std::string input) { // Function to convert userInput to lowercase
    std::string titleCase = input;
    if (!titleCase.empty()) {
        titleCase[0] = std::toupper(titleCase[0]); // Make sure first letter is capitalized
        std::transform(titleCase.begin() + 1, titleCase.end(), titleCase.begin() + 1, ::tolower); // Convert the rest to lowercase
    }
    return titleCase;
}