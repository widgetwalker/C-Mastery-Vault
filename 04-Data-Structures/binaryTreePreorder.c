#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform pre-order traversal
void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    // Visit the current node
    printf("%d ", root->data);

    // Traverse the left subtree
    preOrderTraversal(root->left);

    // Traverse the right subtree
    preOrderTraversal(root->right);
}

// Function to create the binary tree from user input
Node* createTree() {
    Node* root = NULL;
    while (1) {
        int nodeValue;
        printf("Enter a node value (or 0 to quit): ");
        scanf("%d", &nodeValue);
        if (nodeValue == 0) {
            break;
        }
        if (root == NULL) {
            root = createNode(nodeValue);
        } else {
            Node* currentNode = root;
            while (1) {
                printf("Enter 'l' to add to the left or 'r' to add to the right: ");
                char direction;
                scanf(" %c", &direction);
                if (direction == 'l') {
                    if (currentNode->left == NULL) {
                        currentNode->left = createNode(nodeValue);
                        break;
                    } else {
                        currentNode = currentNode->left;
                    }
                } else if (direction == 'r') {
                    if (currentNode->right == NULL) {
                        currentNode->right = createNode(nodeValue);
                        break;
                    } else {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }
    return root;
}

int main() {
    Node* root = createTree();

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    return 0;
}
