# BST Financial Applications
This repository contains an implementation of a Binary Search Tree (BST) tailored for financial applications. It includes functionalities for maintaining order books, managing portfolios, and optimizing trading strategies based on real-time data.

## Features:
Order Book Management: Insert, delete, search, and display orders efficiently.
Portfolio Management: Handle portfolio balances, assets, and transactions.
Real-time Data Handling: Update and optimize strategies based on dynamic market data.
Interactive Command-Line Interface: User-friendly menu for easy interaction.
## Files:
bst.h, bst.c: Binary Search Tree implementation with functions for insertion, deletion, search, and traversal.
main.c: Interactive command-line interface to demonstrate BST operations in financial scenarios.
Order: Struct for storing order details (order ID, price, quantity, side).
Portfolio: Struct for managing portfolio holdings and transactions.
## Usage:
Compile:

```shell
gcc -Wall -Wextra -o bst_financial_app main.c bst.c
```
Run:

```shell
./bst_financial_app
```
## Commands:
Insert an Order: Add a new order to the order book.
Delete an Order: Remove an existing order from the order book.
Search for an Order: Find and display details of a specific order.
Display Order Book: Print the current list of orders in the order book.
Exit: Quit the program.
## Example:
```shell

Financial Application Options:
1. Insert an order
2. Delete an order
3. Search for an order
4. Display order book
5. Exit
Enter your choice: 1
Enter Order ID, Price, Quantity, Side (B/S): 1001 50.25 100 B
Order 1001 inserted successfully.

Financial Application Options:
1. Insert an order
2. Delete an order
3. Search for an order
4. Display order book
5. Exit
Enter your choice: 3
Enter Order ID to search: 1001
Order 1001 found in the order book.

...
```
## Contributors:
Your Name: MamasB
## License:
This project is licensed under the MIT License - see the LICENSE file for details.

