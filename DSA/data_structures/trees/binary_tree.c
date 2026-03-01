
// create a basic binary tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*

            100
        50        150
    25     80  110   200
                        220
                     210
                 205     215
                   209
*/

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int val);
Node* insertNode(Node* root, Node* newNode);
Node* deleteNode(Node* root, int val);
void inorder(Node* root);
int findMinVal(Node* root);
Node* searchNode(Node* root, int val);

void printTree(Node* root) {
    printf("\n--- INORDERN ---\n");
    inorder(root);
    printf("\n");
}

int main(int argc, char** argv) {
    
    int nums[] = {100, 50, 150, 25, 80, 110, 200, 220, 210, 205, 209, 215, 199};
    int len = sizeof(nums) / sizeof(nums[0]);

    Node* root = NULL;
    for (int i = 0; i < len; i++) {
        Node* newNode = createNode(nums[i]);
        root = insertNode(root, newNode);
    }

    printTree(root);

    // search and delete
    int val;
    if (argc > 1) {
        val = atoi(argv[1]);
    } else {
        printf("\nDelete node: ");
        scanf("%d", &val);
    }
    if (searchNode(root, val) != NULL) {
        root = deleteNode(root, val);
        printf("\n>> Node [%d] has been deleted\n", val);
    } else {
        printf("\n>> Node [%d] not found.\n", val);
    }

    printTree(root);

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

Node* deleteNode(Node* root, int val) {
    if (root == NULL) return root;

    if (root->val == val) {
        // leaf
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // two children
        if (root->left != NULL && root->right != NULL) {
            root->val = findMinVal(root->right);
            root->right = deleteNode(root->right, root->val);
            return root;
        }

        // one child
        Node* tmp = NULL;
        if (root->left == NULL) {
            tmp = root->right;
        } else {
            tmp = root->left;
        }
        free(root);
        return tmp;
    }

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } 

    return root;
}

int findMinVal(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return root->val;
    return findMinVal(root->left);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("[%d] ", root->val);
    inorder(root->right);
}


Node* searchNode(Node* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;

    if (val < root->val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }

    return NULL;
}