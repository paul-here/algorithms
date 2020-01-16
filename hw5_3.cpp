/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/dfs-4/submissions/code/1316837813
* Title: hw5_3.cpp
* Abstract: Complete a depth first search and display the mark array.
* Author: Paul Whipp
* ID: 1222
* Date: 10/08/2019
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// returns a matrix initialized to correct values
vector<vector<int>> build_matrix(int n){

    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++) {

        matrix.push_back(vector<int>(n, -1));
        matrix[i][i] = 0;
    }

    return matrix;
}


// adds edge input to passed matrix
void get_edge_input(vector<vector<int>> &matrix, int n) {

    int from, to;

    for(int i = 0; i < n; i++) {

        cin >> from;
        cin >> to;
        
        matrix[from][to] = 1;
    }
}


int main() {

    // get number of nodes and build matrix
    int num_nodes;
    cin >> num_nodes;

    vector<vector<int>> matrix = build_matrix(num_nodes);

    // get number of edges and fill in matrix
    int num_edges;
    cin >> num_edges;

    get_edge_input(matrix, num_edges);

    // prime stack
    int count = 1;
    int tmp_node;
    stack<int> dfs_stack;
    vector<int> mark_array(num_nodes, 0);
    
    dfs_stack.emplace(0);

    // begin DFS
    while(!dfs_stack.empty()){

        tmp_node = dfs_stack.top();
        dfs_stack.pop();
        if(mark_array[tmp_node] == 0){
            mark_array[tmp_node] = count;
            count++;    
        }

        // grab all edges in popped row 
        for(int i = num_nodes - 1; i >= 0; i--) {
            // if there is an edge 
            if(matrix[tmp_node][i] > 0){
                // verify edge is new and add to stack
                if(mark_array[i] == 0) {
                    dfs_stack.emplace(i);
                }
            }
        }
    }

    // display
    for(int i = 0; i < num_nodes; i++){
        cout << "Mark[" << i << "]:" << mark_array[i] << endl;
    }

    return 0;
}