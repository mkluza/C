#include <iostream>
#include "stack.hxx"

using namespace std;

class BinaryTree {
private:
    struct Node {
        Node *left;
        Node *right;
        int x;
    };
    int _size;
    Node *root;
public:
    BinaryTree();

    void insert(int);
    Node *search(int);
    Node *searchRecursive(int, Node *);
    int size();
    int minimum();
    int maximum();
    int depth();
    void printInorder(Node *);
    void printPreorder(Node *);
    void printPostorder(Node *);
    Node *getRoot();
    void printInorderIterative(int);
};

BinaryTree::BinaryTree() {
    root = nullptr;
    _size = 0;
}

void BinaryTree::insert(int w) {
    Node *node = new Node;
    node->x = w;

    if (_size == 0) {
        node->left = nullptr;
        node->right = nullptr;
        root = node;
    } else {
        Node *temp = root;
        int n = _size;
        while (n != 0) {
            if (temp->x >= node->x) {
                if (temp->left == nullptr) {
                    temp->left = node;
                    break;
                } else temp = temp->left;
            } else if (temp->x < node->x) {
                if (temp->right == nullptr) {
                    temp->right = node;
                    break;
                } else temp = temp->right;
            }
            n--;
        }
    }

    _size++;
}

BinaryTree::Node *BinaryTree::search(int w) {
    Node *temp = root;

    while (temp != nullptr && temp->x != w) {
        if (w > temp->x) temp = temp->right;
        if (w < temp->x) temp = temp->left;
    }

    return temp;
}

BinaryTree::Node *BinaryTree::searchRecursive(int w, Node *node) {

    if (node == nullptr) return nullptr;
    if (node->x == w) return node;

    if (node->x < w) searchRecursive(w, node->right);
    if (node->x > w) searchRecursive(w, node->left);
}

int BinaryTree::size() {
    return _size;
}

int BinaryTree::minimum() {
    Node *temp = root;

    while (temp != nullptr && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp->x;
}

int BinaryTree::maximum() {
    Node *temp = root;

    while (temp != nullptr && temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->x;
}

int BinaryTree::depth() {
    return 0;
}

void BinaryTree::printInorder(Node *node) {

    if (node != nullptr) {
        printInorder(node->left);
        cout << node->x << " ";
        printInorder(node->right);
    }

}

void BinaryTree::printPreorder(Node *node) {

    if (node != nullptr) {
        cout << node->x << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void BinaryTree::printPostorder(Node *node) {

    if (node != nullptr) {
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->x << " ";
    }
}

BinaryTree::Node *BinaryTree::getRoot() {
    return root;
}

void BinaryTree::printInorderIterative(int n) {
    Node *stack[n];
    Node *temp = root;
    int s = 0;

    while (s >= 0 || temp != nullptr) {
        if (temp != nullptr) {
            stack[s] = temp;
            s++;
            temp = temp->left;
        } else {
            temp = stack[s];
            s--;
            cout << temp->x << " ";
            temp = temp->right;
        }
    }
}






