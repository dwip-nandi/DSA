#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int n) {
        data = n;
        left = nullptr;
        right = nullptr;
    }
};

node *root = nullptr;

void insert(node *&root, int n) {
    if (root == nullptr) {
        root = new node(n);
    } else if (n <= root->data) {
        insert(root->left, n);
    } else {
        insert(root->right, n);
    }
}

void inorder(node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

void preorder(node *root) {
    if (root == nullptr) return;
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}

bool search(node *root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void findGreaterValues(node *root, int key) {
    if (root == nullptr) return;
    if (root->data > key) {
        cout << root->data << ' ';
        findGreaterValues(root->left, key);
        findGreaterValues(root->right, key);
    } else {
        findGreaterValues(root->right, key);
    }
}

int countOccurrences(node *root, int key) {
    if (root == nullptr) return 0;
    int count = 0;
    if (root->data == key) count++;
    count += countOccurrences(root->left, key);
    count += countOccurrences(root->right, key);
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    cout << "Inorder Traversing: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversing: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversing: ";
    postorder(root);
    cout << endl;

    int key;
    cout << "Enter key to search: ";
    cin >> key;
    if (search(root, key)) {
        cout << "Key found in the tree." << endl;
    } else {
        cout << "Key not found in the tree." << endl;
    }

    cout << "Values greater than " << key << ": ";
    findGreaterValues(root, key);
    cout << endl;

    int count = countOccurrences(root, key);
    cout << "The value " << key << " is present " << count << " times in the tree." << endl;

    return 0;
}
