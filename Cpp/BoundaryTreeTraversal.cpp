//
// Created by ravi on 5/15/17.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printleafBoundary(Node* node){
    if(node){
        printleafBoundary(node->left);

        if(node->left == NULL && node->right==NULL)
            cout<<node->val<<" ";

        printleafBoundary(node->right);
    }
}

void printrightBoundary(Node* node){
    if(node){
        if(node->right){
            printrightBoundary(node->right);
            cout<<node->val<<" ";
        } else if(node->left){
            printrightBoundary(node->left);
            cout<<node->val<<" ";
        }
    }
}

void printleftBoundary(Node* node){
    if(node){
        if(node->left){
            cout<<node->val<<" ";
            printleftBoundary(node->left);
        }
        else if(node->right){
            cout<<node->val<<" ";
            printleftBoundary(node->right);
        }
    }

}



void printBoundary(Node* root){
    if(root == NULL)
        return;

    cout<<root->val<<" ";

    //Print left boundary
    printleftBoundary(root->left);

    //print left leaf boundary
    printleftBoundary(root->left);

    //print right leaf boundary
    printleftBoundary(root->right);

    //print right boundary
    printrightBoundary(root->right);

}
int main(){
    Node* root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left =  newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);
    printBoundary(root);
}