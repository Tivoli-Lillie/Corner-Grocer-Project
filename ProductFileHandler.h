#ifndef PRODUCTFILEHANDLER_H
#define PRODUCTFILEHANDLER_H

#include <iostream>
#include <string>

class ProductFileHandler {
private:
    std::string fileName = ""; // variable for file name
    ProductInventory productInventory; // variable for inventory

public:
    ProductFileHandler(); // Constructor

    void readFile(std::string fileName, ProductInventory& inventory); // Function to read file

    void writeFile(); // Function to write file

    void setFileName(std::string fileName) { // Function to set file name
        this->fileName = fileName;
    };

    void writeFile(const std::string& dataFile, const ProductInventory& inventory); // Function to write data to file
};

#endif