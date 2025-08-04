#include "OrderBook.hpp"
#include "Order.hpp"

int main() {
    OrderBook book; 

    book.addOrder(Order(1, Side::BUY, 100, 10));
    book.addOrder(Order(2, Side::SELL, 100, 10));
    book.addOrder(Order(3, Side::BUY, 90, 5));
    book.addOrder(Order(4, Side::BUY, 91, 5));
    book.addOrder(Order(5, Side::SELL, 92, 5));
    book.addOrder(Order(6, Side::SELL, 95, 5));
    book.addOrder(Order(7, Side::SELL, 95, 5));

    book.printBook();
    
    return 0;
}