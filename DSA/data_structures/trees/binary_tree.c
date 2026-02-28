
// create a basic binary tree

#include <stdio.h>
#include <stdlib.h>

/*

            100
        50        150
    25     80  110   200

*/

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val);
Node* insertNode(Node* root, Node* newNode);
void inorder(Node* root);

int main() {

    int nums[] = {100, 50, 150, 25, 80, 110, 200};
    int len = sizeof(nums) / sizeof(nums[0]);

    Node* root = NULL;
    for (int i = 0; i < len; i++) {
        Node* newNode = createNode(nums[i]);
        root = insertNode(root, newNode);
    }

    printf("\n--- INORDERN ---\n");
    inorder(root);
    printf("\n");

    return 0;
}

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val   = val;
    newNode->left  = NULL;
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
    } 
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("[%d] ", root->val);
    inorder(root->right);
}