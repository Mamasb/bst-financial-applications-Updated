#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void)
{
    bst_t *root = NULL;
    Order order;
    int choice, order_id;
    
    while (1) {
        printf("\nFinancial Application Options:\n");
        printf("1. Insert an order\n");
        printf("2. Delete an order\n");
        printf("3. Search for an order\n");
        printf("4. Display order book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter Order ID, Price, Quantity, Side (B/S): ");
                if (scanf("%d %lf %d %c", &order.order_id, &order.price,
                          &order.quantity, &order.side) != 4) {
                    printf("Invalid input format.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                root = insert(root, order);
                if (root == NULL) {
                    printf("Failed to insert order. Memory allocation error.\n");
                } else {
                    printf("Order %d inserted successfully.\n", order.order_id);
                }
                break;
            case 2:
                printf("Enter Order ID to delete: ");
                if (scanf("%d", &order_id) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                root = delete_node(root, order_id);
                if (root == NULL) {
                    printf("Order %d not found in the order book.\n", order_id);
                } else {
                    printf("Order %d deleted successfully.\n", order_id);
                }
                break;
            case 3:
                printf("Enter Order ID to search: ");
                if (scanf("%d", &order_id) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                if (search(root, order_id)) {
                    printf("Order %d found in the order book.\n", order_id);
                } else {
                    printf("Order %d not found in the order book.\n", order_id);
                }
                break;
            case 4:
                print_order_book(root);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
