#include <iostream>
#include <string>
#include <map>

#include "ProductInventory.h"
#include "Menu.h"
#include "ProductFileHandler.h"

ProductInventory::ProductInventory() {} // Initialize empty inventory

int ProductInventory::findProductfrequency(std::string productName){ // Function to find the frequency of a specific product in the inventory
    if (productInventory.find(productName) != productInventory.end()) { // If product exists
        return productInventory[productName]; // return that product's frequency
    } else {
        return 0; // Exit function if not found
    }
}

bool ProductInventory::checkForProduct(std::string productName) { // Function to check if an product exists in the inventory
    return productInventory.find(productName) != productInventory.end();
}

void ProductInventory::addProduct(std::string productName) {// Function to add a new product to the inventory or increment an existing one
    productName = titleCaseInput(productName); // Convert to title case

    if (this->checkForProduct(productName)) { // If product exists in inventory
        productInventory[productName]++; // Increment the quantity of that product
    } else {
        productInventory[productName] = 1; // Add new product with quantity of 1
    }

}

std::map<std::string, int> ProductInventory::getInventory() const { // Function to get the inventory
    return productInventory;
}

void ProductInventory::printAllFrequency(std::string printFormat) const{ // Function to print all of the product and counts from the inventory
    std::cout << std::endl;
    
    if (productInventory.empty()) {
        std::cout << "There are no products to list." << std::endl; // If inventory is empty, print message
        return; // Exit
    }

    if (printFormat == "list") {
        for (const auto& product : productInventory) { // Loop through each product in the inventory
            std::cout << product.first << " " << product.second << std::endl; // Print each product quantity pair
        }
    } else if (printFormat == "histogram") {

        for (const auto& product : productInventory) { // Loop through each product in the inventory
            std::cout << product.first << " " << std::string(product.second, '*' ) << std::endl; // Print each product quantity pair
        }
        std::cout << std::endl;
    } else {
        std::cout << "Invalid print format." << std::endl; // Error message
    }


}

