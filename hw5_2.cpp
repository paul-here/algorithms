/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/bfs-hops/submissions/code/1316836577
* Title: hw5_2.cpp
* Abstract: This program displays the city names in the range of hops from a starting city.
* Author: Paul Whipp
* ID: 1222
* Date: 10/08/2019
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


struct Node {
    int city;
    int depth;
};

// returns a matrix initialized to correct values
vector<vector<int>> build_matrix(int n){

    vector<vector<int>> matrix;

    for(int i = 0; i < n; i++) {

        matrix.push_back(vector<int>(n, -1));
        matrix[i][i] = 0;
    }

    return matrix;
}

// adds vertice input to passed arrays
void get_vert_input(vector<string> &idx, map<string, int> &names, int n) {

    string temp_str;

    for(int i = 0; i < n; i++) {

        cin >> temp_str;
        names[temp_str] = i;
        idx[i] = temp_str;
    }
}

// adds edge input to passed matrix
void get_edge_input(vector<vector<int>> &matrix, map<string, int> &names, int n) {

    string temp_str;
    string temp_str2;
    
    for(int i = 0; i < n; i++) {

        cin >> temp_str;
        cin >> temp_str2;
        
        matrix[names[temp_str]][names[temp_str2]] = 1;
    }
}


int main() {

    // Collect vertex data and build matrix
    int num_nodes;
    cin >> num_nodes;

    vector<string> vert_index(num_nodes);
    map<string, int> vert_names;

    get_vert_input(vert_index, vert_names, num_nodes);
    
    vector<vector<int>> matrix = build_matrix(num_nodes);

    // Collect edge data and add to matrix
    int num_edges;
    cin >> num_edges;

    get_edge_input(matrix, vert_names, num_edges);

    // Collect starting city and number of hops
    string starting_city;
    int max_hops;

    cin >> starting_city; // grab starting city
    cin >> max_hops; // grab number of hops
    
    
    // Begin BFS
    vector<string> results;
    vector<bool> mark_array(num_nodes, false);
    queue<Node> bfs_q;

    // prime queue
    Node tmp_node;
    bfs_q.emplace(Node{vert_names[starting_city], 0});
    mark_array[vert_names[starting_city]] = true;
    results.push_back(starting_city);

    while(!bfs_q.empty()){

        tmp_node = bfs_q.front();
        bfs_q.pop();
        int curr_depth = tmp_node.depth + 1;

        // grab all edges in popped row 
        for(int i = 0; i < matrix.size(); i++) {
            // if there is an edge 
            if(matrix[tmp_node.city][i] > 0){
                // verify edge is new/target depth has not been passed
                if(!mark_array[i] && curr_depth <= max_hops) {
                    bfs_q.emplace(Node{i, curr_depth});
                    mark_array[i] = true; // visited
                    results.push_back(vert_index[i]);
                }
            }
        }
    }

    // sort and display
    sort(results.begin(), results.end());
    for( string str : results){
        cout << str << endl;
    }
}