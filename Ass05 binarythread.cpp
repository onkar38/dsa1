#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    bool isTh;
};

Node* create(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->isTh = false;
    return newNode;
}

Node* leftmost(Node* node){
    while (node && node->left)
        node = node->left;
    return node;
}

void threadinutil(Node* root, Node*& prev){
    if(root){
        threadinutil(root->left,prev);
        if(prev){
            if(!prev->right){
                prev->right = root;
                prev->isTh = true;
            }
        }
        prev = root;
        threadinutil(root->right, prev);
    }
}

void convert(Node* root){
    Node* prev = nullptr;
    threadinutil(root, prev);
}

void inorder(Node* root){
    Node* cur = leftmost(root);
    while(cur){
        cout<<cur->data<<" ";
        if(cur->isTh)
            cur = cur->right;
        else
            cur=leftmost(cur->right);
    }
}

int main(){
    Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);

    convert(root);
    cout<<"Threaded Inorder Traversal :";
    inorder(root);
    return 0;
}