# 🧾 BBO Order Book Simulator

This is a **single-symbol Limit Order Book simulator** built in C++. It processes buy and sell limit orders, maintains an order book, and matches orders based on price-time priority.

The project focuses on **BBO (Best Bid and Offer)** logic — always tracking the highest bid and lowest ask for a single stock. 

---

## ✅ Features

- Accepts limit **BUY** and **SELL** orders via CLI
- Matches orders if possible based on price/time priority
- Stores unmatched orders in the order book
- Prints current **best bid and best ask (BBO)**

---

## 📌 Example Usage

```text
> BUY 100 150.00
Order added: BUY 100 @ 150.00

> SELL 50 149.00
Matched 50 @ 149.00

> SELL 100 151.00
Order added: SELL 100 @ 151.00

> PRINT
Best Bid: 100 @ 150.00  
Best Ask: 100 @ 151.00
