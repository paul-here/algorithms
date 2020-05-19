/*
* HackerRank link: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
* Title: jumpingclouds.cpp
* Abstract: The jumpingOnClouds() function takes an integer vector representing
*           clouds, with a 0 being a safe cloud and 1 being dangerous. The 
*           shortest safe path is calculated and returned. Code outside of the
*           jumpingOnClouds() function was provided by hackerrank.
* Author: Paul Whipp
* Date: 05/19/2020
*/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {

    int jumps = 0;
    int i = 0;

    while (i != c.size() - 1) {

        if (i + 2 < c.size() && c[i + 2] == 0) {

            i = i + 2;
        
        } else {

            i++;
        }

        jumps++;
    }

    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y && x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}