//
// Created by ravi on 5/14/17.
//
#include <stdio.h>
#include <iostream>

using namespace std;

int count(int i){
    if (i == 2) return 1;
    if (i == 4) return 1;
    if (i< 4) return 0;
    int c1 = count(i-2);
    int c2 = count(i-4);
    return c1+c2;
}

int main(){
    cout<< "Please enter number" <<endl;
    cout << count(3) <<endl;
    cout << count(6) <<endl;
    cout << count(8) <<endl;
    cout << count(12) <<endl;
    cout << count(13) <<endl;

}

