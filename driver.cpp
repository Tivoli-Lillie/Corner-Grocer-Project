#include <iostream>
#include <string>
#include <vector>

#include "Menu.h"
#include "ProductInventory.h"
#include "ProductFileHandler.h"
#include "Product.h"

/*
 * CornerGrocer
 *
 *  Date: 4-17-2025
 *  Author: Tivoli Lillie
 * 
 * This program reads in a list of purchased products and outputs the frequecy of items
 * as a list or as a histogram. Users can search for a specific product or print all products frequencies.
 * 
 */

int main () {
    Menu menu; // Create a menu
    ProductInventory inventory; // Create an inventory
    ProductFileHandler fileHandler; // create a file handler
    std::string fileName = "TestGroceryList.csv"; // File to read from
    int userInput; // variable to hold user input

    // Set file name
    fileHandler.setFileName(fileName);

    // Read in file, put in map
    fileHandler.readFile(fileName, inventory);

    // Write ddata to backup file
    fileHandler.writeFile("frequency.dat", inventory);
    

    // Main loop
    while (true) {
        // Always display the menu after proccessing user input
        menu.displayMenu();

        userInput = menu.getUserInput(userInput); // Get input

        menu.processUserInput(userInput, inventory); // Process input


    }


    return 0;
}


