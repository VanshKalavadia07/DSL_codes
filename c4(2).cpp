#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInorder(Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int choice;
    cout << "Choose traversal:" << endl;
    cout << "1. Inorder" << endl;
    cout << "2. Preorder" << endl;
    cout << "3. Postorder" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Inorder traversal: ";
        printInorder(root);
    } else if (choice == 2) {
        cout << "Preorder traversal: ";
        printPreorder(root);
    } else if (choice == 3) {
        cout << "Postorder traversal: ";
        printPostorder(root);
    } else {
        cout << "Invalid choice";
    }

    cout << endl;
    return 0;
}
