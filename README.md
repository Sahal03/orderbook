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

orderbook.exe < orders.csv 

```
