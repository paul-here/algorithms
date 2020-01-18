/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/recursive-exponents/submissions/code/1316739802
* Title: hw5_1.cpp
* Abstract: This program recursively solves 2^n.
* Author: Paul Whipp
* ID: 1222
* Date: 10/03/2019
*/

#include <iostream>

using namespace std;

int two_to_n(int n){
    
    if(n == 0){
        return 1;
    }

    return 2 * two_to_n(n - 1);
}

int main() {
  
    int n;
    cin >> n;

    cout << two_to_n(n);
}