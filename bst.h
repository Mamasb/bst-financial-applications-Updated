#ifndef BST_H
#define BST_H

typedef struct Order {
    int order_id;
    double price;
    int quantity;
    char side; // 'B' for buy, 'S' for sell
    // Add more fields as needed
} Order;

typedef struct bst_t {
    Order order;
    struct bst_t *left;
    struct bst_t *right;
} bst_t;

bst_t *create_new_node(Order order);
bst_t *insert(bst_t *root, Order order);
bst_t *delete_node(bst_t *root, int order_id);
bst_t *find_min(bst_t *root);
int search(bst_t *root, int order_id);
void inorder(bst_t *root);
void print_order_book(bst_t *root);

#endif /* BST_H */
