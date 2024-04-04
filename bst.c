#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node;

node* root = NULL;

node* add(node* head, int val) {
    if (head == NULL) {
        node* newnode = (node*)malloc(sizeof(node));
        newnode->val = val;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (head->val > val)
        head->left = add(head->left, val);
    else
        head->right = add(head->right, val);

    return head;
}

void inorder(node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {

    root = add(root, 12);
    root = add(root, 45);
    root = add(root, 75);
    root = add(root, 5);
    root = add(root, 364);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
