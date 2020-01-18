/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/time-difference-2/submissions/code/1316134136
* Title: hw2_2.cpp
* Abstract: hw2_2.cpp reads two timestamps from a user and displays
*           the difference between the two timestamps.
* Author: Paul Whipp
* ID: 1222
* Date: 09/09/2019
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    string s;
    int hour, minute, second;

    // get negation of the value of the first event
    getline(cin, s, ':');
    hour = stoi(s) * -1;

    getline(cin, s, ':');
    minute = stoi(s) * -1;

    getline(cin, s, '\n');
    second = stoi(s) * -1;

    // add second event time
    getline(cin, s, ':');
    hour += stoi(s);

    getline(cin, s, ':');
    minute += stoi(s);

    getline(cin, s, '\n');
    second += stoi(s);

    // Rollover correction
    if (second < 0) {
        second += 60;
        minute -= 1;
    }

    if (minute < 0) {
        minute += 60;
        hour -= 1;
    }

    if (hour < 0){
         hour += 24;
    }


    // output
    cout << setw(2) << setfill('0') << hour;
    cout << ":" << setw(2) << setfill('0')  << minute;
    cout << ":" << setw(2) << setfill('0')  << second << endl;
}
