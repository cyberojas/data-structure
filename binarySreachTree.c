#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged node pointer
    return root;
}





void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      //  Root -> Left -> Right
        postorderTraversal(root->left);    
               // Print root
        postorderTraversal(root->right);   
		    }
}

int main() {
    struct Node* root = NULL;  // Create an empty tree

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Print the POST traversal of the BST
    printf("Post Order traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
