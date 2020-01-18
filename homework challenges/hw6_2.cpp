/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/connect-components/submissions/code/1316956008
* Title: hw6_2.cpp
* Abstract: This program connects several connected components of a 
*           graph with minimum number of edges.
* Author: Paul Whipp
* ID: 1222 
* Date: 10/14/2019
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


// checks array for zero values
bool has_zeroes(vector<int> &arr){

    for(int i : arr){
        if( i == 0 ) return true;
    }

    return false;
}


// return index of first 0 value, or -1 if no zeros
int new_low_node(vector<int> &mark_array){

    for(int i = 0; i < mark_array.size(); i++){

        if( mark_array[i] == 0 ) return i;
    }
    
    return -1;
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
    int low_node = 0;
    int old_low_node;
    stack<int> dfs_stack;
    vector<int> mark_array(num_nodes, 0);
    vector<int> connections;
    connections.push_back(0);
        

    while(has_zeroes(mark_array)){

        dfs_stack.emplace(low_node);
        
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

        old_low_node = low_node;
        low_node = new_low_node(mark_array);
        if (low_node > 0) connections.push_back(low_node);
    }

    // display
    if(connections.size() < 2){
        
        cout << "No new edge:" << endl;

    } else {

        for(int i = 0; i < connections.size() - 1; i++) {

            cout << "Edge: " << connections[i] << "-";
            cout << connections[i + 1] << endl;
        }
    }

    return 0;
}