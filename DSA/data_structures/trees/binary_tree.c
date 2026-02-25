
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
void insertNode(Node** root, Node* newNode);
void inorder(Node* root);

int main() {

    int nums[] = {100, 50, 150, 25, 80, 110, 200};
    int len = sizeof(nums) / sizeof(nums[0]);

    Node* root = NULL;
    for (int i = 0; i < len; i++) {
        Node* newNode = createNode(nums[i]);
        insertNode(&root, newNode);
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

void insertNode(Node** root, Node* newNode) {
    
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* tmp = *root;

    if (newNode->val < tmp->val) {
        if (tmp->left == NULL) {
            tmp->left = newNode;
            return;
        } else {
            insertNode(&tmp->left, newNode);
        }
    }

    if (newNode->val > tmp->val) {
        if (tmp->right == NULL) {
            tmp->right = newNode;
            return;
        } else {
            insertNode(&tmp->right, newNode);
        }
    }
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("[%d] ", root->val);
    inorder(root->right);
}