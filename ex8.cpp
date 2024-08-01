#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Insert(Node*& root, int x) {
    if (root == nullptr) {
        root = new Node(x);
    }
    else if (x < root->data) {
        Insert(root->left, x);
    }
    else if (x > root->data) {
        Insert(root->right, x);
    }
}

void InOrderTraversal(Node* root) {
    if (root == nullptr) return;
    InOrderTraversal(root->left);
    std::cout << root->data << " ";
    InOrderTraversal(root->right);
}
//
//int main() {
//    Node* root = nullptr; // Изначально дерево пустое
//
//    Insert(root, 5);
//    Insert(root, 3);
//    Insert(root, 7);
//    Insert(root, 2);
//    Insert(root, 4);
//    Insert(root, 6);
//    Insert(root, 8);
//
//    std::cout << "Дерево после вставки элементов (In-order traversal): ";
//    InOrderTraversal(root);
//    std::cout << std::endl;
//
//    return 0;
//}
