/*
* Repl.it link: https://repl.it/@pwhipp/hw71
* Title: hw7_1.cpp
* Abstract: This program runs a divide-and-conquer find max routine
*           on a user inputted array.
* Author: Paul Whipp
* ID: 1222 
* Date: 10/23/2019
*/

#include <iostream>


using namespace std;

// modified from sum_div_N_conq() found at https://goo.gl/ySZavW 
int findmax_div_N_conq(int A[ ], int start, int end) {
    
    if (start == end) {
        return start;
    }
    else {
        int idx1 = findmax_div_N_conq(A, start, (start+end)/2);
        int idx2 = findmax_div_N_conq(A, (start+end)/2+1, end);

        return (A[idx1] >= A[idx2]) ? idx1 : idx2;
    }
}

int main() {

    // get input
    int n;
    cin >> n;

    int * arr;
    arr = new int [n];

    int temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        arr[i] = temp;
    }

    // run divide-and-conquer find max routine
    int idx = findmax_div_N_conq (arr, 0, n - 1);

    // output result
    cout << "Max index: " << idx << endl;
    return 0;
}