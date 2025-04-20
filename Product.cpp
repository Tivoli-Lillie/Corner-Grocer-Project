#include <iostream>
#include <string>

#include "Product.h"

Product::Product(std::string name) { this->name = name; } // Product must have a name to be created

void Product::setName(std::string productName) { // Function to set product name
    this->name = productName;
}

std::string Product::getName() { // Function to get product name
    return name;
}