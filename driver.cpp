#include <iostream>
#include <string>
#include <vector>

#include "Menu.h"
#include "ProductInventory.h"
#include "ProductFileHandler.h"
#include "Product.h"


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
    

    // Main loop
    while (true) {
        // Always display the menu after proccessing user input
        menu.displayMenu();

        userInput = menu.getUserInput(userInput); // Get input

        menu.processUserInput(userInput, inventory); // Process input

    }

    
    
    // Test, output the inventory map
    // inventory.printAllFrequency();


    



    return 0;
}


