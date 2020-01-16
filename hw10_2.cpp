/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw10/challenges/alien-alphabet/submissions/code/1317851982
* Title: hw10_2.cpp
* Abstract: This program sorts an alien alphabet 
*           given a dictionary.
* Author: Paul Whipp
* ID: 1222 
* Date: 11/19/2019
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> build_matrix(int n){

    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++) {

        matrix.push_back(vector<int>(n, 0));
    }

    return matrix;
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

void display_node_order(
        queue<int> &node_order, 
        vector<char> &chars, 
        int n) {
    

    if(node_order.size() != n){
        
        cout << "Invalid input." << endl;
        return;
    }

    int curr_node = node_order.front();
    node_order.pop();
    cout << chars[curr_node];

    while(!node_order.empty()) {

        cout << "->";

        curr_node = node_order.front();
        node_order.pop();

        cout << chars[curr_node];
    }

    cout << endl;
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

    if(process.size() > 1) return final_order;

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

int main() {

    int n;
    cin >> n;

    vector<string> input;
    string temp;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        input.push_back(temp);
    }

    // scan for verts
    vector<int> count(26, 0);
    for(string str : input) {
        for(char c : str) {
            count[((int) c) - 97]++;
        }
    }

    // condense verts to translation
    // ex: c -> 1 
    unordered_map<char, int> map;
    vector<char> chars;
    int num_verts = 0;
    char temp_char;
    for(int i = 0; i < count.size(); i++) {
        
        if(count[i]) {

            temp_char = (char)(i + 97);
            map.emplace(temp_char, num_verts++);
            chars.push_back(temp_char);
        } 
    }

    // build matrix
    vector<vector<int>> matrix = build_matrix(num_verts);

    // add edges
    int j, k, k_max;
    for(int i = 0; i < input.size() - 1; i++) {

        k = 0;
        
        j = i + 1;

        k_max = min(input[i].length(), input[j].length());

        while(k < k_max) {

            if(input[i][k] == input[j][k]) { 

                k++;

            } else {
                // add edge from input[i][k]
                //           to  input[j][k]
                matrix[map[input[i][k]]][map[input[j][k]]] = 1;
                k = k_max;
            }
        }
    }

    // toposort w/ kahn's algo
    queue<int> node_order = topo_sort(matrix, num_verts);

    // output result
    display_node_order(node_order, chars, num_verts);
}