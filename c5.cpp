#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->data)

        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    Node* stack[20];
    int top = -1;

    Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            top++;
            stack[top] = current;
            current = current->left;
        }
        current = stack[top--];
        cout << current->data << " ";
        current = current->right;
    }
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    Node* stack[20];
    int top = -1;
    top++;
    stack[top] = root;
    while (top != -1) {
        Node* current = stack[top--];
        cout << current->data << " ";

        if (current->right != NULL){
            top++;
            stack[top] = current->right;
        }

        if (current->left != NULL){
            top++;
            stack[top] = current->left;
        }
    }
}


int main() 
{
    Node* root = NULL;

    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);
    return 0;
}
