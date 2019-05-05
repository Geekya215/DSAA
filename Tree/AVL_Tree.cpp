#include <bits/stdc++.h>
using namespace std;

// node structure
struct Node {
    Node* left;
    Node* right;
    int height;
    int value;

    Node(int v)
        :left(nullptr)
        ,right(nullptr)
        ,value(v)
        ,height(0){}

    ~Node();
};


Node* findNode(Node* root, int value) {
    if(root->value == value) return root;

    else {
        if(root->value > value) findNode(root->right, value);
        else findNode(root->left, value);
    }

}


void insertNode(Node* root, int value) {
    if(root == nullptr) root = new Node(value)

    else {
        
    }
}


void deleteNode(Node* root, int value) {
    delete findNode(root, value);
}


void LLrotate(Node* node) {

}


void RRrotate(Node* node) {

}


void LRrotate(Node* node) {

}


void RLrotate(Node* node) {

}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* n = new Node(2);
    cout << n->value << endl;
    return 0;
}