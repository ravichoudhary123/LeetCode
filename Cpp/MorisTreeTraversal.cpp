//
// Created by ravi on 5/5/17.
//
#include <stdio.h>
#include <iostream>


struct Node{
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* findpredecessor(Node* node, Node* current){
    if(node==NULL)
        return NULL;
    while(node->right != current && node->right !=NULL)
        node = node->right;

    return node;
}

void inordertraversal(Node* root){
    if(root==NULL)
        return;

    Node * current = root;

    while(current!=NULL){
        if(current->left==NULL){
            std::cout<<current->value<<" ";
            current = current->right;
        }
        else{
            Node* predecessor = findpredecessor(current->left, current);
            if(predecessor->right!=NULL)
            {
                predecessor->right = NULL;
                std::cout<< current->value<<" ";
                current = current->right;
            }
            else{
                predecessor->right = current;
                current = current->left;
            }
        }
    }
}



int main(){
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    //levelordertraversal(root);
    //iterativePreOrderTraversal(root);
    inordertraversal(root);

    return 0;
}
