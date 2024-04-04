#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node* insertAtBeginning(node* head, int newData) {
    node* newNode = createNode(newData);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

node* insertAtEnd(node* head, int newData) {
    node* newNode = createNode(newData);

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

node* deleteFromBeginning(node* head) {
    if (head == NULL) {
        printf("Cannot delete from an empty doubly linked list.\n");
        return head;
    }

    node* temp = head;

    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }

    free(temp);

    return head;
}

node* deleteFromEnd(node* head) {
    if (head == NULL) {
        printf("Cannot delete from an empty doubly linked list.\n");
        return head;
    }

    node* temp = head;

    if (head->next != NULL) {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);

    return head;
}

void displayList(node* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(node* head) {
    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node* head = NULL;

    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Doubly Linked List after insertAtBeginning: ");
    displayList(head);

    head = insertAtEnd(head, 4);

    printf("Doubly Linked List after insertAtEnd: ");
    displayList(head);

    head = deleteFromBeginning(head);

    printf("Doubly Linked List after deleteFromBeginning: ");
    displayList(head);

    head = deleteFromEnd(head);

    printf("Doubly Linked List after deleteFromEnd: ");
    displayList(head);

    freeList(head);

    return 0;
}
