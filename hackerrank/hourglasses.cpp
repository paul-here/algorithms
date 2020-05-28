/*
* HackerRank link: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
* Title: hourglasses.cpp
* Abstract: The hourglassSum() function takes a 2D vector and calculates the 
*           max sum of hourglass pattern shapes within it. Code outside of the 
*           hourglassSum() function was provided by hackerrank.
* Author: Paul Whipp
* Date: 05/28/2020
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {

    int maxSum = -64;
    int temp = 0;

    for(int i = 0; i < arr.size() - 2; i++) {
        for(int j = 0; j < arr[i].size() - 2; j++) {

            // hourglass top
            temp += arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            // middle
            temp += arr[i + 1][j + 1];
            // bottom
            temp += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];

            // check if max
            if (temp > maxSum) {
                maxSum = temp;
            }
            
            // clear for next loop
            temp = 0;
        }
    }

    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
