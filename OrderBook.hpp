#pragma once

#include <map>
#include <queue>
#include <cstdint>

#include "Order.hpp"

class OrderBook 
{
    private:
        std::map<std::int32_t, std::queue<Order>> bids;
        std::map<std::int32_t, std::queue<Order>> asks;
    
    public:
        void addOrder(const Order& order);
        void printBook() const;
        bool matchOrder(const Order& order);
};