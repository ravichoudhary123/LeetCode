//
// Created by ravi on 5/16/17.
//
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
class Solution{
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int id = 0;
    unordered_map<string, string> m;
    unordered_map<int, string> idm;
public:
    string encode(string longURL){
        if(m.find(longURL)!=m.end()){
            return m[longURL];
        }

        string res = "";
        id++;

        int count = id;
        while(count>0){
            res = dict[count%62] + res;
            count/=62;
        }

        while(res.size() < 6)
        {
            res = "0" + res;
        }

        m[longURL] = res;
        idm[id] = longURL;
        return res;
    }

    string decode(string shortURL){
        int id=0;
        for(int t=0; t<shortURL.size();t++){
            id = 62*id + (int)(dict.find(shortURL[t]));
        }
        if(idm.find(id)!=idm.end())return idm[id];
        return "";
    }
};

int main(){
    Solution solution;
    string encoded = solution.encode("https://leetcode.com/problems/design-tinyurl");
    cout<<encoded<<endl;

    cout<< solution.decode(encoded);
}