//
// Created by ravi on 5/19/17.
//
// Definition for a binary tree node.
#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int temp=0;

    void helper(TreeNode* node){
        if(node==NULL){
            return;
        }

        if(node->right != NULL){
            helper(node->right);
        }

        temp = temp + node->val;
        node->val = temp;

        if(node->left != NULL){
            helper(node->left);
        }

        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        helper(root);

        return root;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(1);

    solution.convertBST(root);

    return 0;
}