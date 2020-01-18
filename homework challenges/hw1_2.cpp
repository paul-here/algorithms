/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/intersection-4/submissions/code/1315966957
* Title: hw1_2.cpp
* Abstract: This program finds the common range between n ranges.
* Author: Paul Whipp
* ID: 1222 
* Date: 08/31/2019
*/

#include <iostream>

using namespace std;

int main(){

    // set up variables
    int n, start, end, max_start, min_end;
    cin >> n;
    cin >> start >> end;

    //set zeroth range as max and min
    max_start = start;
    min_end = end;
    
    // get the rest of the ranges
    for(int i = 1; i < n; i++){

        cin >> start >> end;

        if(start > max_start){

            max_start = start;    
        }

        if(end < min_end){

            min_end = end;
        }
    }

    // no intersection output
    if(min_end < max_start){

        cout << "-1";
        return 0;
    }

    // standard output
    cout << max_start << " " << min_end;
    return 0;
}