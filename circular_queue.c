#include <stdio.h>
#include <stdlib.h>
#define ALLOC(x, size, type) (x = (type*)malloc(size * sizeof(type)))

typedef struct {
    int n;
} Element;

int front = 0, rear = 0, capacity;
Element *queue;

void copy(Element* start, Element* end, Element* newQueue) {
    Element* j = start;
    Element* i = newQueue;
    for (; j < end; j++, i++) {
        *i = *j;
    }
}

void queueFull() {
    Element* newQueue ;
    ALLOC(newQueue, capacity * 2, Element);
    int start = (front + 1) % capacity;
    if (start < 2)
        copy(queue + start, queue + start + capacity - 1, newQueue);
    else {
        copy(queue + start, queue + capacity, newQueue);
        copy(queue, queue + rear + 1, newQueue + capacity - start);
    }
    front = 2 * capacity - 1;
    rear = capacity - 1;
    capacity *= 2;
    free(queue);
    queue = newQueue;
}

void addq(Element item) {
    rear = (rear + 1) % capacity;
    if (front == rear)
        queueFull();
    queue[rear] = item;
}

Element deleteq() {
    Element item;
    if (front == rear) {
        item.n = -1;
    } else {
        front = (front + 1) % capacity;
        item = queue[front];
    }
    return item;
}

void displayq() {
    int i;
    if (front == rear) {
        printf("Queue Empty\n");
    } else {
        for (i = (front + 1) % capacity; i != rear; i = (i + 1) % capacity)
            printf("%d\t", queue[i].n);
        printf("%d", queue[i].n);
        printf("\n");
    }
}

int main() {
    int choice;
    Element item;

    printf("Enter initial size\n");
    scanf("%d", &capacity);
    ALLOC(queue, capacity, Element);

    while (1) {
        printf("1. Add\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to add\n");
                scanf("%d", &item.n);
                addq(item);
                break;
            case 2:
                item = deleteq();
                if (item.n == -1)
                    printf("Queue Empty\n");
                else
                    printf("Item deleted: %d\n", item.n);
                break;
            case 3:
                displayq();
                break;
            case 4:
                free(queue);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
