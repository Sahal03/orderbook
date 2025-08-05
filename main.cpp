#include "OrderBook.hpp"
#include "Order.hpp"

int main() {
    OrderBook book; 

    book.addOrder(Order(2, Side::SELL, 100, 1));
    book.addOrder(Order(3, Side::SELL, 100, 4));
    book.addOrder(Order(1, Side::BUY, 100, 5));
    book.printBook();
    
    return 0;
}