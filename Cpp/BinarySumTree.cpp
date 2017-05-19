//
// Created by ravi on 5/6/17.
//
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int value){
    Node* temp = new Node;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int sum(Node* node){
    if(node==NULL)
        return 0;

    return sum(node->left)+sum(node->right)+node->value;
}

bool isSumTree(Node* node){
    if(node==NULL ||(node->left == NULL && node->right==NULL)){
        return true;
    }

    int sumleft = sum(node->left);
    int sumright = sum(node->right);

    if(((sumleft+sumright) == node->value) && isSumTree(node->left) && isSumTree(node->right))
        return true;
    else
        return false;
}

int main(){
    Node *root = newNode(26);
    root->left        = newNode(10);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    if(isSumTree(root)){
        cout<<"Sum Tree"<<endl;
    } else{
        cout<<"Not a sum tree";
    }


    return 0;
}