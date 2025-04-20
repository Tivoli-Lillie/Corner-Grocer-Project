#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product{
private:
    std:: string name; // variable for product name

public:
    Product(std::string name); // Constructor

    void setName(std::string productName); // Function to set product name

    std::string getName(); // Function to get product name
};

#endif