
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val);
Node* insertNode(Node* root, Node* newNode);
int getHeight(Node* n);
void setHeight(Node** n);
int max(int a, int b);
Node* rightRotation(Node* n);
Node* leftRotation(Node* n);

void preorden(Node* root);

int main() {

    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(nums) / sizeof(nums[0]);

    Node* root = NULL;

    for (int i = 0; i < size; i++) {
        Node* newNode = createNode(nums[i]);
        root = insertNode(root, newNode);  
    }

    preorden(root);
    printf("\n");

    return 0;
}

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        root = newNode;
        return root;
    }

    if (newNode->val < root->val) {
        root->left = insertNode(root->left, newNode);
    } else if (newNode->val > root->val) {
        root->right = insertNode(root->right, newNode);
    } else {
        return root;
    }

    setHeight(&root);

    int balanceFactor = getHeight(root->left) - getHeight(root->right);

    // todo
    if (balanceFactor < -1) return leftRotation(root);
    if (balanceFactor > 1)  return rightRotation(root);

    return root;
}

Node* leftRotation(Node* n) {
    Node* tmp = n->right;
    Node* tmp2 = tmp->left;

    tmp->left = n;
    n->right = tmp2;

    setHeight(&n);
    setHeight(&tmp);

    return tmp;
}

Node* rightRotation(Node* n) {
    Node* tmp = n->left;
    Node* tmp2 = tmp->right;

    tmp->right = n;
    n->left = tmp2;

    setHeight(&n);
    setHeight(&tmp);

    return tmp;
}

// helper functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* n) {
    if (n == NULL) return 0;
    return n->height;
}

void setHeight(Node** n) {
    if (n == NULL) return;

    int hLeft = getHeight((*n)->left);
    int hRight = getHeight((*n)->right);

    (*n)->height = max(hLeft, hRight) + 1;
}

void preorden(Node* root) {
    if (root == NULL) return;
    printf("[N: %d - H: %d]\n", root->val, root->height);
    preorden(root->left);
    preorden(root->right);
}