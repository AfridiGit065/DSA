#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* root = NULL;

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode();
    newNode->key = value;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertInBST(int value) {
    TreeNode* z = createNode(value);
    TreeNode* y = NULL;
    TreeNode* x = root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;
    if (y == NULL) {
        root = z;  // Tree was empty
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void preOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    cout << ptr->key << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    inOrder(ptr->left);
    cout << ptr->key << " ";
    inOrder(ptr->right);
}

void postOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->key << " ";
}

TreeNode* minimum(TreeNode* x) {
    if (x == NULL) return NULL;
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

TreeNode* maximum(TreeNode* x) {
    if (x == NULL) return NULL;
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}

TreeNode* findKthSmallest(TreeNode* node, int& k) {
    if (node == NULL) return NULL;

    // Search in the left subtree
    TreeNode* left = findKthSmallest(node->left, k);
    if (left != NULL) return left; // Found in the left subtree

    // Visit current node
    k--;
    if (k == 0) return node;

    // Search in the right subtree
    return findKthSmallest(node->right, k);
}

void displayMinMax() {
    TreeNode* maxNode = maximum(root);
    TreeNode* minNode = minimum(root);
    if (maxNode) cout << "Maximum value: " << maxNode->key << endl;
    if (minNode) cout << "Minimum value: " << minNode->key << endl;
}

int main() {
    int n, value, k;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertInBST(value);
    }

    cout << "\nPre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    displayMinMax();

    cout << "\nEnter the value of K to find the K-th smallest node: ";
    cin >> k;

    TreeNode* kthNode = findKthSmallest(root, k);
    if (kthNode != NULL) {
        cout << "The K-th smallest node value is: " << kthNode->key << endl;
    } else {
        cout << "The value of K is invalid!" << endl;
    }

    return 0;
}

