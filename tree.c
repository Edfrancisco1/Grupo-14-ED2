#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* Contador privado para numeração automática */
static int nextNum = 1;

int getNextNum(void) {
    return nextNum++;
}

Node* createNode(Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, Data data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data.num < root->data.num) {
        root->left = insert(root->left, data);
    } else if (data.num > root->data.num) {
        root->right = insert(root->right, data);
    }
    return root;
}

Node* search(Node* root, int num) {
    if (root == NULL || root->data.num == num)
        return root;

    if (num < root->data.num)
        return search(root->left, num);
    else
        return search(root->right, num);
}

static Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* removeNode(Node* root, int num) {
    if (root == NULL) return root;

    if (num < root->data.num) {
        root->left = removeNode(root->left, num);
    } else if (num > root->data.num) {
        root->right = removeNode(root->right, num);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data.num);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("  [num: %d | nome: %s | telefone: %s]\n",
               root->data.num, root->data.name, root->data.phone);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("  [num: %d | nome: %s | telefone: %s]\n",
               root->data.num, root->data.name, root->data.phone);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void posOrder(Node* root) {
    if (root != NULL) {
        posOrder(root->left);
        posOrder(root->right);
        printf("  [num: %d | nome: %s | telefone: %s]\n",
               root->data.num, root->data.name, root->data.phone);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}