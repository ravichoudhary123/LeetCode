//
// Created by ravi on 5/19/17.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



int maxfreqSubTreeUtil(TreeNode* node, unordered_map<int,int> &fc, int& maxCount){
    if(node==NULL){
        return 0;
    }

    int count = 0;
    int lcount = 0;
    int rcount = 0;
    if(node->left!=NULL){
        lcount = maxfreqSubTreeUtil(node->left, fc, maxCount);
    }

    if(node->right!=NULL){
        rcount = maxfreqSubTreeUtil(node->right, fc, maxCount);
    }

    count = rcount + lcount + node->val;

    if(fc.find(count) == fc.end()) {
        fc[count] = 1;
        maxCount = max(maxCount, fc[count]);
    }
    else{
        fc[count] += 1;
        maxCount = max(maxCount, fc[count]);
    }
    fc.insert(make_pair(count, maxCount));
    return count;
}

vector<int> maxfreqSubTree(TreeNode* node){
    if(node==NULL){
        return vector<int>(0);
    }
    int maxed = 0;
    unordered_map<int, int> freqcount;
    unordered_map<int,int> maxcount;
    vector<int> res;
    maxfreqSubTreeUtil(node, freqcount, maxed);
//    for(auto& x:freqcount){
//        if(maxcount.find(x.second) == maxcount.end()) {
//            maxcount[x.second] = 1;
//            maxed = max(maxed, maxcount[x.second]);
//        }
//        else{
//            maxcount[x.second] += 1;
//            maxed = max(maxed, maxcount[x.second]);
//        }
//
//    }

    for(auto& y: freqcount){
        if(maxed == y.second){
            res.push_back(y.first);
        }
    }
    return res;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    //root->right = new TreeNode(-3);
    vector<int> output = maxfreqSubTree(root);
    for(auto& x:output){
        cout<<x<<" ";
    }
}
