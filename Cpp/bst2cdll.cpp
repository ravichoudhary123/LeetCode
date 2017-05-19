//
// Created by ravi on 5/6/17.
//

#include <stdio.h>
#include <queue>
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

Node* bst2dll(Node* root){
    if(root == NULL)
        return NULL;

    Node* last = NULL;
    Node* pres = NULL;

    queue<Node*> bq;

    bq.push(root);

    while (!bq.empty()){
        pres = bq.front();
        bq.pop();
        if(pres->left!=NULL){
            bq.push(pres->left);
        }

        if(pres->right!=NULL){
            bq.push(pres->right);
        }

        pres->left = last;
        pres->right = bq.front();
        last = pres;
    }

    return root;
}

Node* concatenatedList(Node* leftList, Node* rightList){
    if(leftList==NULL)
        return rightList;

    if(rightList==NULL)
        return leftList;

    Node* leftMost = leftList->left;
    Node* rightMost = rightList->left;

    leftMost->right = rightList;
    rightList->left = leftMost;

    leftList->left = rightMost;
    rightMost->right = leftList;

    return leftList;
}

Node* bst2cdll(Node* root){
    if(root==NULL){
        return NULL;
    }

    Node* leftList = bst2cdll(root->left);

    Node* rightList = bst2cdll(root->right);

    root->left = root->right = root;

    return concatenatedList(concatenatedList(leftList,root), rightList);
}

void displaydll(Node* head){
    Node* currentNode = head;

    do{
        cout<<currentNode->value << " ";

        currentNode = currentNode->right;
    }while(head!=currentNode);
}

int main(){
    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    //Node* head = bst2dll(root);
    Node*chead = bst2cdll(root);
    displaydll(chead);

    return 0;
}
