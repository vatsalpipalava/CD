#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to insert a new node with given key in BST
struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(struct Node *root, struct Node **pre, struct Node **suc, int key)
{
    // Base case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->key == key)
    {
        // The maximum value in the left subtree is predecessor
        if (root->left != NULL)
        {
            struct Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            *pre = tmp;
        }

        // The minimum value in the right subtree is successor
        if (root->right != NULL)
        {
            struct Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            *suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // Go to right subtree
    {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Driver program to test above function
int main()
{
    int key = 65; // Key to be searched in BST

    // Let us create the BST
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    struct Node *pre = NULL, *suc = NULL;
    findPreSuc(root, &pre, &suc, key);

    if (pre != NULL)
        printf("Predecessor is %d\n", pre->key);
    else
        printf("No Predecessor\n");

    if (suc != NULL)
        printf("Successor is %d\n", suc->key);
    else
        printf("No Successor\n");

    return 0;
}