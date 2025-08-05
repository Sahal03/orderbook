#pragma once

#include <cstdint>
#include <iostream>
enum class Side {
    BUY,
    SELL
};

class Order 
{
    private:
        std::uint64_t orderId;
        std::uint32_t price;
        std::uint32_t quantity;
        Side side;

    public:
        Order(std::uint64_t orderId_, Side side_, std::uint32_t price_, std::uint32_t quantity_) 
            : orderId(orderId_), side(side_), price(price_), quantity(quantity_) {}
        std::uint32_t GetPrice() const {return price;}
        std::uint32_t GetQuantity() const {return quantity;}
        std::uint64_t GetOrderId() const {return orderId;}
        Side GetSide() const {return side;}

        void fill(Order& other) {
            std::uint32_t matchedQty = std::min(quantity, other.quantity);
            quantity -= matchedQty;     
            other.quantity -= matchedQty;
        }

        void toString() const {
            std::cout << "Order added: " << (side == Side::BUY ? "BUY " : "SELL ") << quantity << " @ " << price << std::endl;
        }
};