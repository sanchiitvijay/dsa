#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Polynomial;

void initializePolynomial(Polynomial* poly) {
    poly->head = NULL;
}

void insertTerm(Polynomial* poly, int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    if (poly->head == NULL) {
        poly->head = newNode;
    } else {
        Node* temp = poly->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result;
    initializePolynomial(&result);

    Node* term1 = poly1.head;
    Node* term2 = poly2.head;

    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent > term2->exponent) {
            insertTerm(&result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else if (term1->exponent < term2->exponent) {
            insertTerm(&result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        } else {
            int sumCoefficients = term1->coefficient + term2->coefficient;
            insertTerm(&result, sumCoefficients, term1->exponent);
            term1 = term1->next;
            term2 = term2->next;
        }
    }

    while (term1 != NULL) {
        insertTerm(&result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }

    while (term2 != NULL) {
        insertTerm(&result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    }

    return result;
}

void displayPolynomial(Polynomial poly) {
    Node* current = poly.head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;

        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(Polynomial* poly) {
    while (poly->head != NULL) {
        Node* temp = poly->head;
        poly->head = poly->head->next;
        free(temp);
    }
}

int main() {
    Polynomial poly1, poly2, result;
    initializePolynomial(&poly1);
    initializePolynomial(&poly2);
    initializePolynomial(&result);

    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 7, 0);

    insertTerm(&poly2, 2, 2);
    insertTerm(&poly2, 4, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    freePolynomial(&poly1);
    freePolynomial(&poly2);
    freePolynomial(&result);

    return 0;
}
