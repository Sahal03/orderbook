#include "OrderBook.hpp"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    order.toString();

    if(matchOrder(order)) {
        return; 
    }
    if (order.GetSide() == Side::BUY) {
        bids[order.GetPrice()].push(order);
    } else {
        asks[order.GetPrice()].push(order);
    }
}

void OrderBook::printBook() const {
    if (asks.empty() && bids.empty()) {
        std::cout << "No orders in the book." << std::endl;
        return;
    }
    for (const auto& [price, orders] : asks){
        std::cout << "ASK: " << orders.size() <<  (orders.size() == 1 ? " Order" : " Orders") << " @ " << price << std::endl;
    }
    for (const auto& [price, orders] : bids){
        std::cout << "BID: " << orders.size() << (orders.size() == 1 ? " Order" : " Orders") << " @ " << price << std::endl;
    }
}

bool OrderBook::matchOrder(const Order& order) {
    if (order.GetSide() == Side::BUY) {
        auto it = asks.lower_bound(order.GetPrice());
        if (it != asks.end() && it->first <= order.GetPrice()) {
            auto& orderQueue = it->second;
            if (!orderQueue.empty()) {
                Order matchedOrder = orderQueue.front();
                orderQueue.pop();

                std::cout << "Matched BUY Order " << order.GetOrderId() 
                          << " with SELL Order " << matchedOrder.GetOrderId() 
                          << " at price " << it->first << std::endl;


                if (orderQueue.empty()) {
                    asks.erase(it); 
                }
                return true;
            }
        }
    } else {
        auto it = bids.lower_bound(order.GetPrice());
        if (it != bids.end() && it->first >= order.GetPrice()) {
            auto& orderQueue = it->second;
            if (!orderQueue.empty()) {
                Order matchedOrder = orderQueue.front();
                orderQueue.pop();

                std::cout << "Matched SELL Order " << order.GetOrderId() 
                          << " with BUY Order " << matchedOrder.GetOrderId() 
                          << " at price " << it->first << std::endl;

                if (orderQueue.empty()) {
                    bids.erase(it);
                }
                return true;
            }
        }
    }
    return false;
}