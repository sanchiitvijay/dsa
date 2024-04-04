#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* insertAtBeginning(node* head, int newData) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    return head;
}

node* insertAtEnd(node* head, int newData) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

node* deleteFromFront(node* head) {
    if (head == NULL) {
        printf("Cannot delete from an empty linked list.\n");
        return head;
    }

    node* temp = head;

    if (head->next != NULL) {
        head = head->next;
    } else {
        head = NULL;
    }

    free(temp);

    return head;
}

node* deleteFromRear(node* head) {
    if (head == NULL) {
        printf("Cannot delete from an empty linked list.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

node* deleteByValue(node* head, int deleteValue) {
    if (head == NULL) {
        printf("Cannot delete from an empty linked list.\n");
        return head;
    }

    if (head->data == deleteValue) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* temp = head;
    while (temp->next != NULL && temp->next->data != deleteValue) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    } else {
        printf("Value %d not found in the linked list.\n", deleteValue);
    }

    return head;
}

void displayList(node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
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

    printf("Linked List after insertAtBeginning: ");
    displayList(head);

    head = insertAtEnd(head, 4);

    printf("Linked List after insertAtEnd: ");
    displayList(head);

    head = deleteFromFront(head);

    printf("Linked List after deleteFromFront: ");
    displayList(head);

    head = deleteFromRear(head);

    printf("Linked List after deleteFromRear: ");
    displayList(head);

    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Linked List before deleteByValue: ");
    displayList(head);

    head = deleteByValue(head, 3);

    printf("Linked List after deleteByValue: ");
    displayList(head);

    freeList(head);

    return 0;
}
