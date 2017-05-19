//Created by ravi on 5/5/17.

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
};

void levelordertraversal(Node *root){
    queue<Node *> lq;
    lq.push(root);
    while(1) {
        int ncount = lq.size();
        if (ncount == 0)
            break;
        while (ncount >0) {
            Node *temp = lq.front();
            if (temp->left != NULL) {
                lq.push(temp->left);
            }

            if (temp->right != NULL) {
                lq.push(temp->right);
            }

            cout << temp->value << " ";

            lq.pop();
            ncount--;

        }
        cout << endl;
    }
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void iterativePreOrderTraversal(Node *root){
    if(root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty()){
        Node* temp = s.top();
        cout<<temp->value<<" ";
        s.pop();
        if(temp->right!=NULL){
            s.push(temp->right);
        }
        if(temp->left!=NULL){
            s.push(temp->left);
        }

    }
}

void iterativeInOrder(Node *root){
    if (root==NULL){
        return;
    }
    stack<Node *> s;
    s.push(root);
    Node* current = root;
    while (current !=NULL && !s.empty()){
        while (current!=NULL){
            current = current->left;
            if(current!=NULL)
                s.push(current);
        }
        while(current==NULL && !s.empty()){
            Node* retrieved = s.top();
            cout<< retrieved->value << " ";
            current = retrieved->right;
            s.pop();
        }
        s.push(current);
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
    iterativeInOrder(root);

    return 0;
}
