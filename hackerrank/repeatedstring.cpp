/*
* HackerRank link: https://www.hackerrank.com/challenges/repeated-string/problem
* Title: repeatedstring.cpp
* Abstract: The repeatedString() function finds how many occurances of the letter
*           'a' that there will be if a string pattern is repeated until there
*           are n characters. Code outside of the repeatedString() function was
*           provided by hackerrank.
* Author: Paul Whipp
* Date: 05/22/2020
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long count = 0;

    // get total repetitions and remainder
    long reps = n / s.length();
    int remainder = n % s.length();

    // get count of a full pass
    long temp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') temp++;
    }

    // add to count
    count = reps * temp;

    // get count of partial pass
    temp = 0;
    for (int i = 0; i < remainder; i++) {
        if (s[i] == 'a') temp++;
    }
    
    // add to count
    count += temp;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
