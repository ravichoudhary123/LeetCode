
 Created by ravi on 5/18/17.

#include <vector>
#include <iostream>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for(vector<int>::iterator it = nums.begin(); it<nums.end();it++){
        if(nums.operator[](abs(*it)-1)<0){
           result.push_back(abs(*it));
        }
        else{
            nums.operator[](abs(*it)-1) = -1*nums.operator[](abs(*it)-1);
        }

    }
    return result;
    vector<int> res;
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] != nums[nums[i]-1])
            swap(nums[i], nums[nums[i]-1]);
        else
            i++;
    }
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) res.push_back(nums[i]);
    }
    return res;
}

int main(){
    int array[] = {4,3,2,7,8,2,3,1};
    vector<int> nums(array, array+sizeof(array)/ sizeof(array[0]));
    vector<int> duplicates = findDuplicates(nums);
    for(vector<int>::iterator it = duplicates.begin(); it<duplicates.end(); it++){cout<<*it<<endl;}
    return 0;
}
