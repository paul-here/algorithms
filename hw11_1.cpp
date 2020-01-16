/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-row/submissions/code/1318189880
* Title: hw11_1.cpp
* Abstract: This program evaluates a line of coins and finds the highest value assuming no consecutive selections.
* Author: Paul Whipp
* ID: 1222
* Date: 12/5/2019
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool no_consecutive(vector<bool> arr){

    for(int i = 0; i < arr.size() - 1; i++){
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
    vector<int> coin_row;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        coin_row.push_back(temp);
    }

    // start summing up apples
    vector<bool> combo_arr(n, false);
    vector<bool> winning_combo;
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
                    sum += coin_row[j];
                }
            }
        }

        // save if new max
        if(sum > max_sum){
            max_sum = sum;
            winning_combo = combo_arr;
        }

        // next combo
        sum = 0;
        binary_plus_one(combo_arr);
    }

    cout << "Best set:";

    for(int i = 0; i < n; i++){
        
        if(winning_combo[i]){
            cout << i + 1 << " ";
        }
    }

    cout << endl;
    cout << "Max value:" << max_sum << endl;
}