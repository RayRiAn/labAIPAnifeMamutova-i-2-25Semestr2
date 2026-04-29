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

void printTree(Node* root, int space = 0) {
    if (root == NULL) return;
    
    space += 10; 
    
    printTree(root->right, space); 
    
    cout << endl;
    for (int i = 10; i < space; i++) cout << " ";
    cout << root->data << endl;
    
    printTree(root->left, space); 
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
    
    cout << "\n\n дерево до зеркала" << endl;
    printTree(root);
    
    cout << "\n\nОбход (по возрастанию): ";
    print(root);
    
    root = mirror(root);
    
    cout << "\n\n дерево после зеркала" << endl;
    printTree(root);
    
    cout << "\n\nОбход (по убыванию после зеркала): ";
    print(root);
    
    cout << endl << endl;
    return 0;
}