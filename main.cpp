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
