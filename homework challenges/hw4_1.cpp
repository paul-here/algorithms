/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/buy-two-one-free/submissions/code/1316419891
* Title: hw4_1.cpp
* Abstract: This program calculates the best price for a 
*           “buy-two-get-one-free” deal.
* Author: Paul Whipp
* ID: 1222 
* Date: 09/20/2019
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int free_items = n / 3;
    int sum = 0;
    vector<int> input_vec(n);

    for(int i = 0; i < n; i++) cin >> input_vec[i];
    
    sort(input_vec.be   gin(), input_vec.end());

    for(int i = 0; i < n - free_items; i++) sum += input_vec[i];

    cout << sum << endl;
}