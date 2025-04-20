#ifndef PRODUCTINVENTORY_H
#define PRODUCTINVENTORY_H

#include <iostream>
#include <string>
#include <map>

class ProductInventory {
private:
    std::map<std::string, int> productInventory; // Map to hold product quantity pairs

public:
    ProductInventory(); // Constructor

    int findProductfrequency(std::string productName); // Function to find the frequency of a specific product in the inventory

    void printAllFrequency() const; // Function to print all of the product and counts from the inventory

    bool checkForProduct(std::string productName); // Function to check if an product exists in the inventory

    void addProduct(std::string productName); // Function to add a new product to the inventory or increment an existing one

    const std::map<std::string, int> getProductInventory(); // Function to get the whole inventory
};

#endif