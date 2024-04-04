// Online C compiler to run C program online
#include <stdio.h>

typedef struct poly{
    int coeff;
    int exp;
}poly;

poly p1[100];
int n,m;

int add() {
    int i = 0; 
    int j = n;
    int k = m+n;
    
    while(i<n && j<m+n) {
        if(p1[i].exp == p1[j].exp) {
            p1[k].exp = p1[i].exp;
            p1[k++].coeff = p1[i++].coeff + p1[j++].coeff;
        }
        else if(p1[i].exp < p1[j].exp) {
            p1[k].exp = p1[i].exp;
            p1[k++].coeff = p1[i++].coeff;
        }
        else {
            p1[k].exp = p1[j].exp;
            p1[k++].coeff = p1[j++].coeff;
        }
    }
    
    while(i<n) {
        p1[k].exp = p1[i].exp;
        p1[k++].coeff = p1[i++].coeff;
    }
    while(j<m+n) {
        p1[k].exp = p1[j].exp;
        p1[k++].coeff = p1[j++].coeff;
    }
    
    return k;
}

void inputpoly() {
    int c,e;
    printf("\nEnter the size of the poly: ");
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
        scanf("%d %d", &c, &e);
        p1[i].exp = e;
        p1[i].coeff = c;
    }
    printf("\n------\n");
    printf("\nEnter the size of another poly: ");
    scanf("%d", &m);
    for(int i = n; i<m+n; i++) {
        scanf("%d %d", &c, &e);
        p1[i].exp = e;
        p1[i].coeff = c;
    }
}

void display(int k) {
    printf("\nAdded poly is: \n");
    for(int i = m+n; i<k; i++) {
        printf("%dx^%d + ", p1[i].coeff, p1[i].exp);
    }
}


int main() {
     inputpoly();
     int k = add();
     display(k);

    return 0;
}