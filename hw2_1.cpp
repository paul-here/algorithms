/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/binary-numbs/submissions/code/1316133614
* Title: hw2_1.cpp
* Abstract: hw2_1.cpp reads a positive integer number from a user and
*           displays all binary numbers from 0 to the number.
* Author: Paul Whipp
* ID: 1222
* Date: 09/09/2019
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int bool_to_bit(bool val){
    if(val){
        return 1;
        }
    return 0;
}


void print_bits(int n){

    if(n == 0){
        cout << 0 << endl;
        return;
    }

    bool carry = false;
    int i = 0;
    int num_bits = floor(log(n)/log(2)) + 1;
    // boolean binary: true == 1, false == 0
    vector<bool> bit_array(num_bits);

    // print zeroth
    for(int j = 0; j < num_bits; j++){
        cout << bool_to_bit(bit_array[j]);
    }
    cout << endl;

    // begin iterating to n
    while(i < n){

        // add 1, prepare to carry if needed
        if(bit_array[num_bits - 1]){
            carry = true;
        }
        bit_array[num_bits - 1] = !bit_array[num_bits - 1];

        // loop to carry
        for(int j = num_bits - 2; j >= 0; j--){
            if(carry){
                if(bit_array[j]){
                    carry = true;
                } else {
                    carry = false;
                }
                bit_array[j] = !bit_array[j];
            }
        }

        // loop to print
        for(int j = 0; j < num_bits; j++){
            cout << bool_to_bit(bit_array[j]);
        }

        cout << endl;
        i++;
    }
}


int main() {

    int n;
    cin >> n;

    print_bits(n);
}
