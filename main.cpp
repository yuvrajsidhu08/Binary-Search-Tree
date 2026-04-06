#include <iostream> 
#include <cstring>
#include <cstdlib>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* create(int v) {
    Node* n = new Node;
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

// Insert a value into the BST
Node* insert(Node* root, int v) {
    if (!root) return create(v);
    if (v < root->data) root->left = insert(root->left, v);
    else if (v > root->data) root->right = insert(root->right, v);
    return root;
}

// Find the minimum node in a subtree
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Remove a node with a given value
Node* removeNode(Node* root, int v) {
    if (!root) return NULL;

    if (v < root->data) root->left = removeNode(root->left, v);
    else if (v > root->data) root->right = removeNode(root->right, v);
    else {
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Search for a value in the BST
bool search(Node* root, int v) {
    if (!root) return false;
    if (root->data == v) return true;
    return v < root->data ? search(root->left, v) : search(root->right, v);
}

// Print the BST sideways
void printTree(Node* root, int space) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->data << endl;
    printTree(root->left, space);
}

// Add numbers from a string to the BST
void addNumbers(Node*& root, char input[]) {
    char* token = strtok(input, " ");
    while (token) {
        int num = atoi(token);
        if (num >= 1 && num <= 999) root = insert(root, num);
        token = strtok(NULL, " ");
    }
}

// Main program loop
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

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;

        // Add numbers to the BST
        if (strcmp(command, "add") == 0) {
            cin.ignore();
            char line[200];
            cout << "Enter numbers: ";
            cin.getline(line, 200);
            addNumbers(root, line);
        }
        // Remove a number from the BST
        else if (strcmp(command, "remove") == 0) {
            int x;
            cout << "Number to remove: ";
            cin >> x;
            root = removeNode(root, x);
        }
        // Search for a number in the BST
        else if (strcmp(command, "search") == 0) {
            int x;
            cout << "Number to search: ";
            cin >> x;
            cout << (search(root, x) ? "Found\n" : "Not found\n");
        }
        // Print the BST
        else if (strcmp(command, "print") == 0) {
            cout << "\nTree:\n";
            printTree(root, 0);
        }
        // Quit the program
        else if (strcmp(command, "quit") == 0) {
            break;
        }
// Handle invalid commands
        else {
            cout << "Invalid command.\n";
        }
    }
}
