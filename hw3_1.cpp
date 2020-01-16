/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/palindrome-check-10/submissions/code/1316256250
* Title: hw3_1.cpp
* Abstract: Checks a string to see if it is a palindrome.
* Author: Paul Whipp
* ID: 1222 
* Date: 09/14/2019
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h> 

using namespace std;

int main() {
  
    string s;
    getline(cin, s);

    int idxStart = 0;
    int idxEnd = s.length() - 1;

    // tolower code from: www.geeksforgeeks.org
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    while(idxStart < idxEnd){

        // Skip non-aplhanumeric chars
        while(!isalnum(s[idxStart])) idxStart++;
        while(!isalnum(s[idxEnd])) idxEnd--;

        if(s[idxStart] != s[idxEnd]){

            cout << "FALSE" << endl;
            return 0;
        }

        idxStart++;
        idxEnd--;
    }

    cout << "TRUE" << endl;
    return 0;
}