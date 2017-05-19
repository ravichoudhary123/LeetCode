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

int bt2st(Node* node){
    if(node==NULL)
        return 0;

    int x;

    if(node->left == NULL && node->right==NULL) {
        //node->sum = 0;
        x = node->value;
        node->value = 0;
        return x;
    }

    //node->sum = leftsum + rightsum;
    x = node->value;

    node->value = bt2st(node->left); + bt2st(node->right);;

    return x + node->value;
}

Node* newNode(int value){
    Node* temp = new Node;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    bt2st(root);

    return 0;
}