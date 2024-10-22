#include <stdio.h>
#include <stdlib.h>

// Define the structure for the nodes of the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in the BST
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // Insert at the root if the tree is empty
    }

    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert into the left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data); // Insert into the right subtree
    }

    return root;
}

// Function for Root-Right-Left traversal (modified pre-order traversal)
void printRootRightLeft(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);          // Visit root
        printRootRightLeft(root->right);    // Visit right subtree
        printRootRightLeft(root->left);     // Visit left subtree
    }
}

int main() {
    struct Node* root = NULL;

    // Inserting nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Root-Right-Left Traversal of the BST: \n");
    printRootRightLeft(root);

    return 0;
}
