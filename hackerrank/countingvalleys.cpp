/*
* HackerRank link: https://www.hackerrank.com/challenges/counting-valleys/problem
* Title: countingvalleys.cpp
* Abstract: The countValleys() function takes an string of chars representing
*           slope, and returns the number of valleys that dip below sea level.
*           Code outside of the sockMerchant() function was provided by 
*           hackerrank, with the exception of 'include <bits/stdc++>' being
*           changed to the individual headers.
* Author: Paul Whipp
* Date: 05/17/2020
*/


#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int count = 0;
    int elevation = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') {
            // exiting a valley
            if(elevation++ == -1) {
                count++;
            }
        } else {
            elevation--;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}