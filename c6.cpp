#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void printLevelOrder(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize > 0) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
            }

            levelSize--;
        }

        cout << endl;
    }
}

Node* copyTree(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* newNode = new Node(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int getHeight(Node* root) {
    if (root == nullptr) {
        return -1;
    }

    return 1 + max(getHeight(root->left),
                   getHeight(root->right));
}

void printLeafNodes(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    Node* root = nullptr;
    Node* newRoot = nullptr;
    int n, val;

    cout << "Enter the number of employee IDs: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid number of employee IDs." << endl;
        return 0;
    }

    cout << "Enter " << n << " employee IDs:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nOriginal BST (Level Order):" << endl;
    printLevelOrder(root);

    newRoot = copyTree(root);

    cout << "\nCopied BST (Level Order):" << endl;
    printLevelOrder(newRoot);

    if (root == nullptr) {
        cout << "\nHeight of BST: -1 (Empty tree)" << endl;
    } else {
        cout << "\nHeight of BST: " << getHeight(root) << endl;
    }

    cout << "Leaf Nodes: ";

    if (root == nullptr) {
        cout << "None";
    } else {
        printLeafNodes(root);
    }

    cout << endl;

    return 0;
}
