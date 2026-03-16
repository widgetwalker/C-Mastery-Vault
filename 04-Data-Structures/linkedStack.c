#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!newNode) {
        printf("Stack Overflow!\n");
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to pop an element from the stack
int pop(Node** head) {
    if (*head == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Function to peek the top element of the stack
int peek(Node* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return head->data;
}

// Function to print the stack
void printStack(Node* head) {
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    printf("Stack: ");
    printStack(stack);
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Stack: ");
    printStack(stack);
    return 0;
}
