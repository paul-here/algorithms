/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/radix-sort-4-1/submissions/code/1317771010
* Title: hw10_1.cpp
* Abstract: This program conducts a radix sort and 
*           displays the intermediate steps.
* Author: Paul Whipp
* ID: 1222 
* Date: 11/19/2019
*/

#include <iostream>
#include <vector>

using namespace std;


void display(vector<int> &vec){
    for( int i : vec ) {
        
        cout << i << " ";
    }

    cout << endl;
}

int ith_place(int n, int mod_val) {

    // remove excess left
    n = n % mod_val;

    // remove excess right
    n /= mod_val/10;

    return n;
}

int main() {

    // get input, find max value
    int n, max_val, temp;
    vector<int> input;
    
    cin >> n;
    // prime the find_max routine
    cin >> max_val;
    input.push_back(max_val);

    for(int i = 1; i < n; i++) {
        
        cin >> temp;
        
        if(temp > max_val) max_val = temp;

        input.push_back(temp);
    }

    //for every digit place, count sort
    vector<int> count(10, 0);
    vector<int> output(n);
    int mod_val = 10;

    while(max_val > 0) {

        // find frequency
        for(int i = 0; i < n; i++) {
        
            count[ith_place(input[i], mod_val)]++;
        }
        // convert to placement indices 
        for(int i = 1; i < 10; i++) {

            count[i] += count[i - 1];
        }
        // shift to align
        for(int i = 9; i > 0; i--) {

            count[i] = count[i - 1];
        }
        count[0] = 0;
        // count is now placement indices...
        
        // place everything into output
        for(int i = 0; i < n; i++) {
            
            temp = ith_place(input[i], mod_val);
            temp = count[temp]++;

            output[temp] = input[i];
        }

        display(output);

        // clear count and advance vars
        fill(count.begin(), count.end(), 0);
        input = output;
        max_val /= 10;
        mod_val *= 10;
    }
}