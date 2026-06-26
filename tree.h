#ifndef TREE_H
#define TREE_H

typedef struct Data {
    int num;
    char name[50];
    char phone[20];
} Data;

typedef struct Node {
    Data data;
    struct Node *left;
    struct Node *right;
} Node;

/* Gera o próximo número automático */
int getNextNum(void);

Node* createNode(Data data);
Node* insert(Node* root, Data data);
Node* search(Node* root, int num);
Node* removeNode(Node* root, int num);
void inOrder(Node* root);
void preOrder(Node* root);
void posOrder(Node* root);
void freeTree(Node* root);

#endif