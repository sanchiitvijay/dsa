#include <stdio.h>
#include <stdlib.h>
typedef struct Heap {
    int arr[100];
    int size;
}heap;

void insertToHeap(heap* h, int val) {
    h->size += 1;
    h->arr[h->size] = val;
    int index = h->size;
    while(index > 1) {
        if(h->arr[index] > h->arr[index/2]) {
            int tmp = h->arr[index];
            h->arr[index] = h->arr[index/2];
            h->arr[index/2] = tmp;
            index = index/2;
        }
        else return ;
    }
}

int deleteFromHeap(heap* h) {
    int deletedNum = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size -= 1;
    
    heapify(h, 1);
    return deletedNum;
}

void heapify(heap* h, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
    
    if(left < h->size && h->arr[largest] < h->arr[left]) {
        largest = left;
    }
    if(right < h->size && h->arr[largest] < h->arr[right]) {
        largest = right;
    }
    
    if(largest != i) {
        int tmp = h->arr[i];
        h->arr[i] = h->arr[largest];
        h->arr[largest] = tmp;
        heapify(h, largest);
    }
    
}

void print(heap* h) {
    int n = h->size;
    printf("\n");
    for(int i = 1; i<=n; i++) {
        printf("%d ", h->arr[i]);
    }
}


int main() {
    heap* h = (heap*)malloc(sizeof(heap));
    h->arr[0] = -1;
    h->size = 0;
    insertToHeap(h, 65);
    print(h);
    insertToHeap(h, 5);
    print(h);
    insertToHeap(h, 6);
    print(h);
    insertToHeap(h, 45);
    print(h);
    insertToHeap(h, 48);
    print(h);
    insertToHeap(h, 81);
    print(h);
    insertToHeap(h, 10);
    print(h);
    
    printf("\n%d ", deleteFromHeap(h));
    print(h);
    printf("\n%d ", deleteFromHeap(h));
    print(h);
    printf("\n%d ", deleteFromHeap(h));
    print(h);
    printf("\n%d ", deleteFromHeap(h));
    print(h);
    return 0;
}