#include <iostream>
#include <queue>

using namespace std;

// Definition of BST Node
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

// Function to insert a node into the BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// 1. Level-wise traversal (Breadth-First Search)
void printLevelOrder(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize > 0) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
            levelSize--;
        }
        cout << "| "; // Separator for different levels
    }
    cout << endl;
}

// 2. Calculate the height of the tree
int getHeight(Node* root) {
    if (root == nullptr) return -1; // Returns -1 if height is edge-based, 0 if node-based
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// 3. Mirror the tree (Invert left and right children)
void mirrorTree(Node* root) {
    if (root == nullptr) return;

    // Swap left and right child pointers
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// 4. Print all leaf nodes
void printLeafNodes(Node* root) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int n, val;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values to build the BST:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\n--- Binary Search Tree Details ---\n";
   
    cout << "Level-wise Traversal: ";
    printLevelOrder(root);

    cout << "Height of the Tree: " << getHeight(root) << endl;

    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Mirroring the tree...\n";
    mirrorTree(root);

    cout << "Level-wise Traversal of Mirror Tree: ";
    printLevelOrder(root);

    return 0;
}

