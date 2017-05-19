//
// Created by ravi on 5/16/17.
//
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        int count =0;
        vector<int>::iterator start = A.begin();
        vector<int>::iterator end = A.end();

        for(int i =2; i<A.size(); i++){
            for(int j = 0; j<A.size()-i;j++){
                vector<int>::iterator temp_start = start+j;
                vector<int>::iterator temp_end = start+j+i;
                if(isArithmetic(temp_start,temp_end)){
                    count++;
                }
            }
        }
        return count;

    }

    bool isArithmetic(vector<int>::iterator start, vector<int>::iterator end){
        int gap = *(start+1) - *start;
        for(start++;start<end;start++){
            if((*(start+1) - *start)!=gap)
                return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    int arr[] = {1, 2, 3, 4};
    vector<int>A(arr, arr+ sizeof(arr)/sizeof(arr[0]));
    int count = solution.numberOfArithmeticSlices(A);
    cout<<count;
}