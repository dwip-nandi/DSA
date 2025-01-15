/*------------------------Problem3------------------------------------------
3. Create a program in your preferred programming language (e.g., Python, C++, Java)
   that allows the user to: 
(a) Declare a Binary Search tree. 
(b) insert value into the BST. 
(c) Trevarse the BST in preorder/inorder/postorder . 
(e) Print all values of node greater than or equals to a given input by user.
----------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

void printGreaterEqual(Node* root, int key) {
    if (root != nullptr) {
        printGreaterEqual(root->left, key);
        if (root->key >= key) {
            cout << root->key << " ";
        }
        printGreaterEqual(root->right, key);
    }
}

// Example usage
int main() {
    BST bst;
    bst.root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int value : values) {
        bst.root = insert(bst.root, value);
    }

    cout << "Inorder traversal: ";
    inorder(bst.root);
    cout << "\nPreorder traversal: ";
    preorder(bst.root);
    cout << "\nPostorder traversal: ";
    postorder(bst.root);

    int user_input;
    cout << "\nEnter a value to print nodes greater than or equal to: ";
    cin >> user_input;
    cout << "Nodes greater than or equal to " << user_input << ": ";
    printGreaterEqual(bst.root, user_input);

    return 0;
}
