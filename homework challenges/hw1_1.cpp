/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/370-hw1-1/submissions/code/1315966086
* Title: hw1_1.cpp
* Abstract: This program finds the minimum distance between any two
*           integers in a given list.
* Author: Paul Whipp
* ID: 1222 
* Date: 08/31/2019
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // set up variables
    int n, tmp, min_diff, a, b;
    cin >> n;
    vector<int> vec(n);

    // add data to array
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    
    // setup first pair as min_diff
    a = vec[0];
    b = vec[1];
    min_diff = a - b;
    if(min_diff < 0){
        min_diff *= -1;
    }

    // check all pairs if there are more than 1
    if(n > 2){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                
                tmp = vec[i] - vec[j];
                
                if(tmp < 0){
                    tmp *= -1;
                }
                
                if(tmp < min_diff){
                    min_diff = tmp;
                    a = vec[i];
                    b = vec[j];
                }
            }
        }
    }

    // fix a, b order
    if(b < a){
        tmp = a;
        a = b;
        b = tmp;
    }

    // output result
    cout << "Min distance: " << min_diff << endl;
    cout << "Two numbers for min distance: " << a;
    cout << " and " << b << endl;
    
}