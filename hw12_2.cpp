/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/floyd-all-pairs-shortest-paths/submissions/code/1318346925
* Title: hw12_2.cpp
* Abstract: This program performs Floyd's algorithm on a given matrix.
* Author: Paul Whipp
* ID: 1222
* Date: 12/11/2019
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// returns a matrix initialized to correct values
vector<vector<int>> build_matrix(int n){

    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++) {

        matrix.push_back(vector<int>(n));

        for(int j = 0; j < n; j++) {

            cin >> matrix[i][j];
        }
    }

    return matrix;
}


void floyds_algo(vector<vector<int>> &matrix, int n) {

    int matrix_ji, matrix_ik, temp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {

                matrix_ji =  matrix[j][i];
                matrix_ik =  matrix[i][k];
                
                if(matrix_ik != -1 && matrix_ji != -1) {

                    temp = matrix_ik + matrix_ji;

                    if(matrix[j][k] == -1 || matrix[j][k] > temp) {

                        matrix[j][k] = temp;
                    }
                }
            }
        }
    }
}


void print_2d(vector<vector<int>> vec) {

    for ( vector<int> &v : vec ){
        for ( int x : v){
            cout << x << ' ';
        }
        
        cout << endl;
    }
}


int main() {

    // Collect edge data and build matrix
    int num_nodes;
    cin >> num_nodes;
    vector<vector<int>> matrix = build_matrix(num_nodes);

    // Run algorithm
    floyds_algo(matrix, num_nodes);

    // Display
    print_2d(matrix);
}