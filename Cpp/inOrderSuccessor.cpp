
//Created by ravi on 5/6/17.

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node* next;
};



Node* newNode(int value){
    Node* temp = new Node;
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    temp->next = NULL;
    return temp;
}

Node* getnextNode(Node* current){

}

void setordersuccessor(Node* root){
    if(root==NULL)
        return;
    static Node* next = NULL;

    //if left subtree exist get rightmost element
    if(root!=NULL)
    {
        setordersuccessor(root->right);

        root->next = next;

        next = root;

        setordersuccessor(root->left);
    }

}

int main(){
    Node *root = newNode(26);
    root->left        = newNode(10);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    setordersuccessor(root);

    Node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->value, ptr->next? ptr->next->value: -1);
        ptr = ptr->next;
    }

    return 0;
}