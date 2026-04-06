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

bool search(Node* root, int v) {
    if (!root) return false;
    if (root->data == v) return true;
    return v < root->data ? search(root->left, v) : search(root->right, v);
}

void printTree(Node* root, int space) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->data << endl;
    printTree(root->left, space);
}

void addNumbers(Node*& root, char input[]) {
    char* token = strtok(input, " ");
    while (token) {
        int num = atoi(token);
        if (num >= 1 && num <= 999)
            root = insert(root, num);
        token = strtok(NULL, " ");
    }
}

int main() {
    Node* root = NULL;
    char command[20];

    cout << "Binary Search Tree Program\n";
    cout << "Commands:\n";
    cout << "  add     -> enter numbers (space separated)\n";
    cout << "  remove  -> delete a number\n";
    cout << "  search  -> check if a number exists\n";
    cout << "  print   -> display tree\n";
    cout << "  quit\n";

}

