#include <iostream>
#include <string>
#include <fstream>
#include "ProductInventory.h"


#include "ProductFileHandler.h"

ProductFileHandler::ProductFileHandler() { } // User does not give filename


void ProductFileHandler::readFile(std::string fileName, ProductInventory& inventory) { // Function to read file
    std::string line = ""; // variable to hold line
    std::ifstream reader; // create file reader
    
    reader.open(fileName); // open file
    std::cout << "Reading file..." << std::endl;

    // Error handling
    if(!reader.is_open()) { // If it cannot open file
        std::cout << "Error: Could not open file " << fileName << std::endl; // Print error message
        return; // Exit
    }

    int count = 0;
    while (getline(reader,line)) { // continue reading until end of file
        count++; // Increment count
        inventory.addProduct(line); // Add product to inventory
    }
    std::cout << "Added " << count << " products to inventory." << std::endl;

    reader.close(); // Close the file
}

void ProductFileHandler::writeFile() { // Function to write file
    // TODO: Define this fucntion
}

