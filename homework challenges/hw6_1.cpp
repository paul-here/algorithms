/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/apple-collection/submissions/code/1316954520
* Title: hw6_1.cpp
* Abstract: This program finds the maximum number of apples that can be collected from boxes under the given conditions.
* Author: Paul Whipp
* ID: 1222 
* Date: 10/14/2019
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool no_consecutive(vector<bool> arr){

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] && arr[i + 1]) return false;
    }

    return true;
}

void binary_plus_one(vector<bool> &arr){

    bool carry = false;

    // add 1, prepare to carry if needed
    if(arr[arr.size() - 1]){
        carry = true;
    }
    arr[arr.size() - 1] = !arr[arr.size() - 1];

    // loop to carry
    for(int j = arr.size() - 2; j >= 0; j--){
        if(carry){
            if(arr[j]){
                carry = true;
            } else {
                carry = false;
            }
            arr[j] = !arr[j];
        }
    }
}


int main() {
  
    int n;
    cin >> n;

    // get apples
    vector<int> apple_boxes;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        apple_boxes.push_back(temp);
    }

    // start summing up apples
    vector<bool> combo_arr(n, false);
    int combos = int(pow(2, n) - 1); 
    int sum = 0;
    int max_sum = 0;

    // skip past 0
    binary_plus_one(combo_arr);

    //loop through combos
    for(int i = 0; i < combos; i++){

        // sum up a valid set
        if (no_consecutive(combo_arr)) {
            for(int j = 0; j < n; j++){

                if(combo_arr[j]) {
                    sum += apple_boxes[j];
                }
            }
        }

        // save if new max
        if(sum > max_sum){
            max_sum = sum;
        }

        // next combo
        sum = 0;
        binary_plus_one(combo_arr);
    }

    cout << "Max Apples: " << max_sum << endl;
}