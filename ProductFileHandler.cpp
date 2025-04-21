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
    std::cout << "Added " << count << " products to the inventory." << std::endl << std:: endl;

    reader.close(); // Close the file
}

void ProductFileHandler::writeFile(const std::string& dataFile, const ProductInventory& inventory) { // Function to write file
    //write data to file
    std::ofstream writer; // create writer

    writer.open(dataFile); // Open file

    // Error handling
    if (!writer.is_open()) { // If it cannot open file
        std::cout << "Error: Could not open file " << dataFile << std::endl; // Print error message
        return; // Exit
    }

    // Write inventory data to the file
    const auto& productMap = inventory.getInventory(); // Get the inventory
    for (const auto& product : productMap) {
        writer << product.first << " " << product.second << std::endl; // Write product name and frequency
    }

    // std::cout << "Data successfully written to " << dataFile << std::endl;

    writer.close(); // Close the file


    
}

