#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_t *create_new_node(Order order)
{
    bst_t *new_node = malloc(sizeof(bst_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }
    new_node->order = order;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bst_t *insert(bst_t *root, Order order)
{
    if (root == NULL)
        return create_new_node(order);

    if (order.order_id < root->order.order_id)
        root->left = insert(root->left, order);
    else if (order.order_id > root->order.order_id)
        root->right = insert(root->right, order);

    return root;
}

bst_t *delete_node(bst_t *root, int order_id)
{
    if (root == NULL)
        return root;

    if (order_id < root->order.order_id)
        root->left = delete_node(root->left, order_id);
    else if (order_id > root->order.order_id)
        root->right = delete_node(root->right, order_id);
    else {
        if (root->left == NULL) {
            bst_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }

        bst_t *temp = find_min(root->right);
        root->order = temp->order;
        root->right = delete_node(root->right, temp->order.order_id);
    }
    return root;
}

bst_t *find_min(bst_t *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

int search(bst_t *root, int order_id)
{
    if (root == NULL)
        return 0;
    if (order_id == root->order.order_id)
        return 1;
    if (order_id < root->order.order_id)
        return search(root->left, order_id);
    return search(root->right, order_id);
}

void inorder(bst_t *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("Order ID: %d, Price: %.2f, Quantity: %d, Side: %c\n",
           root->order.order_id, root->order.price,
           root->order.quantity, root->order.side);
    inorder(root->right);
}

void print_order_book(bst_t *root)
{
    if (root == NULL) {
        printf("Order book is empty.\n");
        return;
    }
    printf("Current Order Book:\n");
    inorder(root);
}
