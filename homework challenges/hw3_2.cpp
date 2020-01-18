/*
* HackerRank link: 
* Title: hw3_2.cpp
* Abstract: This program divides input into equal sets.
* Author: Paul Whipp
* ID: 1222 
* Date: 09/14/2019
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> binary_plus_one(vector<bool> arr){

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

    return arr;
}

int main() {

    // get/store/sort input
    int n, temp;
    vector<int> input_arr(n);
    cin >> n;

    for(int i = 0; i < n; i++){
        
        cin >> temp;
        input_arr.push_back(temp);
    }
    sort(input_arr.begin(), input_arr.end());

    // use a boolean array to find all set combinations 
    int combos = int(pow(2, n) - 1);
    vector<bool> bit_array(n);
    //vector<int> final_set;
    int set1_sum = 0;
    int set2_sum = 0;

    // begin iterating through all combos
    int i = 0;
    while(i < combos){

        // divide and test sets
        for(int j = 0; j < n; j++){
            
            if(bit_array[j]) {
                set1_sum += input_arr[j];
            } else {
                set2_sum += input_arr[j];
            }
        }
        
        if(set1_sum == set2_sum) {

            cout << "Equal Set: ";

            for(int j = 0; j < input_arr.size(); j++){
                if(!bit_array[j]) {
                    cout << input_arr[j] << " ";
                }
            }

            cout << endl;
            return 0;
        }
        
        bit_array =  binary_plus_one(bit_array);
        i++;
        set1_sum = 0;
        set2_sum = 0;
    }

    cout << "Equal Set: 0" << endl;
    return 0;
}