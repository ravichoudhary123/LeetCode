//
// Created by ravi on 5/18/17.
//

#include <queue>
#include <iostream>
#include <algorithm>

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

vector<int> printlre(Node* root){
    if(root == NULL){
        return vector<int>(0);
    }

    queue<Node*> tq;
    vector<int> res, ret;

    tq.push(root);
    ret.push_back(root->val);
    cout<<root->val<<endl;
    while (1){
        int len = tq.size();
        if(len == 0){
            break;
        }
        while (len>0){
            Node* temp = tq.front();
            if(temp->left!=NULL){
                tq.push(temp->left);
                res.push_back(temp->left->val);
            }
            if(temp->right!=NULL){
                tq.push(temp->right);
                res.push_back(temp->right->val);
            }
            tq.pop();
            len--;
        }
        for (unsigned i=0; i<res.size(); i++)
            std::cout << res[i]<< " ";
        cout<<endl;
        if(!tq.empty()) {
            ret.push_back(*max_element(res.begin(), res.end()));
            std::fill(res.begin(), res.end(), 0);
        }
        //cout<<res.size();
    }
    return ret;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(2);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->right = newNode(9);
    vector<int> maxelements = printlre(root);

    return 0;
}