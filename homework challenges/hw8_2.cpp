/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/kahns-topological-sort/submissions/code/1317271081
* Title: hw8_2.cpp
* Abstract: This program conducts a topological sort using Kahn's 
*           Algorithm.
* Author: Paul Whipp
* ID: 1222 
* Date: 10/27/2019
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

vector<vector<int>> build_matrix(int n){

    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++) {

        matrix.push_back(vector<int>(n, 0));
        //matrix[i][i] = 0;
    }

    return matrix;
}

void get_edge_input(vector<vector<int>> &matrix, int n) {

    int temp1, temp2;
    
    for(int i = 0; i < n; i++) {

        cin >> temp1;
        cin >> temp2;
        
        matrix[temp1][temp2] = 1;
    }
}

vector<int> get_in_degs(vector<vector<int>> &matrix, int n) {

    int sum;
    vector<int> in_degs;

    for(int i = 0; i < n; i++){

        sum = 0;

        for(int j = 0; j < n; j++){

            sum += matrix[j][i];
        }

        in_degs.push_back(sum);
    }

    return in_degs;
}

void display_in_degs(vector<int> &in_degs, int n) {

    for(int i = 0; i < n; i++) {
        cout << "In-degree[" << i << "]:" << in_degs[i] << endl;
    }
}

queue<int> topo_sort(vector<vector<int>> &matrix, int n) {

    queue<int> final_order;

    // get nodes with degree 0
    vector<int> in_degs = get_in_degs(matrix, n);

    // place 0 deg nodes in processing queue to prime it
    queue<int> process;
    for(int i = 0; i < n; i++) {
    
        if(in_degs[i] == 0) {
    
            process.emplace(i);
        }
    }

    while( !process.empty() ){

        // get node to process
        int curr_node = process.front();
        process.pop();

        // add to processing order queue
        final_order.emplace(curr_node);

        // delete from matrix
        int edge_val;
        int num_edges;
        for(int i = 0; i < n; i++) {
            
            edge_val = matrix[curr_node][i];

            // if curr_node is connected to the ith node...
            if(edge_val == 1) {

                in_degs[i] -= 1;
                // and if last connection has been severed, add to process
                if(in_degs[i] == 0){
                    process.emplace(i);
                }
            }
        }
    }

    return final_order;
}

void display_node_order(queue<int> node_order, int n) {

    if(node_order.size() != n){

        cout << "No Order:" << endl;
        return;
    }

    cout << "Order:";

    int curr_node = node_order.front();
    node_order.pop();
    cout << curr_node;

    while(!node_order.empty()) {

        cout << "->";

        curr_node = node_order.front();
        node_order.pop();

        cout << curr_node;
    }

    cout << endl;
}


int main() {

    // Collect vertex data and build matrix
    int num_nodes;
    cin >> num_nodes;
    vector<vector<int>> matrix = build_matrix(num_nodes);

    // Collect edge data and add to matrix
    int num_edges;
    cin >> num_edges;
    get_edge_input(matrix, num_edges);

    // display initial in-degrees
    vector<int> in_degs = get_in_degs(matrix, num_nodes);
    display_in_degs(in_degs, num_nodes);

    // Topo sort and display
    queue<int> node_order = topo_sort(matrix, num_nodes);
    display_node_order(node_order, num_nodes);
}
