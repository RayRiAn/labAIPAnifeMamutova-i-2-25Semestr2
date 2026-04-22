#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

Node* mirror(Node* root) {
    if (root == NULL) return NULL;
    
    Node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    
    return root;
}

void print(Node* root) {
    if (root == NULL) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main() {
    srand(time(NULL));
    
    Node* root = NULL;
    
    cout << "Числа: ";
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        cout << num << " ";
        root = insert(root, num);
    }
    
    cout << "\nДо зеркала: ";
    print(root);
    
    root = mirror(root);
    
    cout << "\nПосле зеркала: ";
    print(root);
    
    cout << endl;
    return 0;
}