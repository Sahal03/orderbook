#include <iostream>
#include <sstream>

#include "OrderBook.hpp"
#include "Order.hpp"

int main() {
    OrderBook orderBook;
    std::uint64_t orderIdCounter = 0;

    while(true){
        std::string choice;
        std::cout << "Choose an option:\n1. Add Order\n2. Print Order Book\n3. Exit\n";
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::string input;
            std::cout << "Enter order (format: <side> <price> <quantity>):\n"; 
            std::getline(std::cin, input);

            std::istringstream iss(input);
            std::string sideStr;
            std::uint32_t price, quantity;

            if (!(iss >> sideStr >> price >> quantity)) {
                std::cerr << "Invalid input format. Please try again." << std::endl;
                continue;
            }

            Side side = (sideStr == "BUY") ? Side::BUY : Side::SELL;

            orderBook.addOrder(Order(orderIdCounter++, side, price, quantity));
        } else if (choice == "2") {
            orderBook.printBook();
        } else {
            break;
        }
    }
    return 0;
}