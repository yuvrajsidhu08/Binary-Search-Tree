#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create(int v) {
    Node* n = new Node;
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int v) {
    if (!root) return create(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* removeNode(Node* root, int v) {
    if (!root) return NULL;

    if (v < root->data) root->left = removeNode(root->left, v);
    else if (v > root->data) root->right = removeNode(root->right, v);
    else {
        if (!root->left && !root->right) return delete root, NULL;
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}
