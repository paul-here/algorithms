/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/knapsack-7-1/submissions/code/1318375849
* Title: hw12_1.cpp
* Abstract: Runs a dynamic knapsack algorithm
* Author: Paul Whipp
* ID: 1222
* Date: 12/12/2019
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Partial credit to geeksforgeeks.com 
void knapsack_it_to_me(vector<vector<int>> &vec, int w, int v) {

    for(int i = 0; i < vec.size(); i++) {

        for(int j = 0; j < vec[i].size() - 2; j++) {

            if (i==0 || j==0) {

                vec[i][j] = 0; 

            } else if (vec[i-1][w] <= j) {

                vec[i][j] = max(vec[i-1][v] + vec[i-1][j - vec[i-1][w]],  vec[i-1][j]); 

            } else {

                vec[i][j] = vec[i-1][j]; 
            }
        }
    }
}


void display_final(vector<vector<int>> &vec) {

    int last_vec = vec.size() - 1;
    int cap = vec[0].size() - 2;

    cout << "Final step:";

    for(int i = 0; i < cap; i++) {
        cout << vec[last_vec][i] << ' ';
    }

    cout << endl;
}


void display_max(vector<vector<int>> &vec) {

    int last_vec = vec.size() - 1;
    int max = vec[0].size() - 3;

    cout << "Max value:";
    cout << vec[last_vec][max] << endl;
}


void display_backtrace(vector<vector<int>> &vec, int w) {

    stack<int> items;

    int i = vec.size() - 1;
    int j = vec[0].size() - 3;
    
    
    while(i > 0) {
        
        if(vec[i][j] == vec[i - 1][j]) {

            i--;

        } else {

            items.push(i);
            j = j - vec[i - 1][w];
            i--;
        }
    }

    cout << "Items:";

    while(!items.empty()) {
        
        cout << items.top() << " ";
        items.pop();
    }

    cout << endl;
}


int main() {

    // get initial input
    int num_items, capacity;
    cin >> num_items;
    cin >> capacity;

    // set up memory
    vector<vector<int>> matrix;
    // set index values for weight/value storage
    int weight = capacity + 1;
    int value = capacity + 2;

    // establish size, leave room for 0 column
    // and item values, get input
    // first push for base case...
    matrix.push_back(vector<int>(capacity + 3));
    for(int i = 0; i < num_items; i++) {
        
        matrix.push_back(vector<int>(capacity + 3));
        cin >> matrix[i][weight];
        cin >> matrix[i][value];
    }

    // run knapsack algorithm
    knapsack_it_to_me(matrix, weight, value);

    // output
    display_final(matrix);
    display_max(matrix);
    display_backtrace(matrix, weight);
}