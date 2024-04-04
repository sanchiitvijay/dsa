#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Cannot pop from an empty stack.\n");
        return -1;
    }

    int poppedData = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);

    return poppedData;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Cannot peek into an empty stack.\n");
        return -1;
    }

    return stack->top->data;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);

    printf("Stack elements: ");
    displayStack(&myStack);

    printf("Top element: %d\n", peek(&myStack));

    int poppedElement = pop(&myStack);
    printf("Popped element: %d\n", poppedElement);

    printf("Stack elements after popping: ");
    displayStack(&myStack);

    freeStack(&myStack);

    return 0;
}
