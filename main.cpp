#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "OrderBook.hpp"
#include "Order.hpp"

int main() {
    OrderBook orderBook;
    std::uint64_t orderIdCounter = 0;

    std::string line;

    while(std::getline(std::cin, line)) {
        std::istringstream ss(line);
        std::string sideStr, strPrice, strQuantity;
        std::uint32_t price;
        std::uint32_t quantity;
        
        std::getline(ss, sideStr, ',');
        std::getline(ss, strPrice, ',');
        std::getline(ss, strQuantity, ',');
        
        if(sideStr.empty() || strPrice.empty() || strQuantity.empty()) {
            continue;
        }

        price = static_cast<uint32_t>(std::stoul(strPrice));
        quantity = static_cast<uint32_t>(std::stoul(strQuantity));

        Side side = (sideStr == "BUY") ? Side::BUY : Side::SELL;
        Order order(orderIdCounter++, side, price, quantity);
        orderBook.addOrder(order);
        orderBook.printBook();    
    }
        

    
    return 0;
}