# BBO Order Book Simulator

This is a **single-symbol Limit Order Book simulator** built in C++. It processes buy and sell limit orders, maintains an order book, and matches orders based on price-time priority.

The project focuses on **BBO (Best Bid and Offer)** logic — always tracking the highest bid and lowest ask for a single stock. 

---

## How to Use

### Compile

Run the following command in your terminal (requires g++):

```sh
g++ -std=c++17 main.cpp OrderBook.cpp -o orderbook
```

### Run

```sh
./orderbook
```

Follow the CLI prompts to enter BUY/SELL orders and print the book.

---

## Features

- Accepts limit **BUY** and **SELL** orders via CLI
- Matches orders if possible based on price/time priority
- Stores unmatched orders in the order book
- Prints current **best bid and best ask (BBO)**

---

## Example Usage

```text

Choose an option:
1. Add Order
2. Print Order Book
3. Exit
1

Enter order (format: <side> <price> <quantity>):
BUY 150 100
Order added: BUY 100 @ 150

Choose an option:
1. Add Order
2. Print Order Book
3. Exit
1

Enter order (format: <side> <price> <quantity>):
BUY 151 50
Order added: BUY 50 @ 151

Choose an option:
1. Add Order
2. Print Order Book
3. Exit
1

Enter order (format: <side> <price> <quantity>):
SELL 151 50
Matched BUY Order 1 with SELL Order 2 at price 151

Choose an option:
1. Add Order
2. Print Order Book
3. Exit
2

Order Book:
BID: 100 Order @ 150

Choose an option:
1. Add Order
2. Print Order Book
3. Exit
3
```
