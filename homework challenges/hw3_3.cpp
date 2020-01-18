/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/adjacency-list/submissions/code/1316316457
* Title: hw3_3.cpp
* Abstract: This program constructs an adjacency list from directed 
*           graph data and then displays it.
* Author: Paul Whipp
* ID: 1222 
* Date: 09/15/2019
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_adj_list(vector<vector<int>> &adj_list){

    for(int i = 0; i < adj_list.size(); i++) {

        cout << i;

        for(int j = 0; j < adj_list[i].size(); j++){
            cout << "->" << adj_list[i][j];
        }
        
        cout << endl;
    }
}


void add_verts(vector<vector<int>> &adj_list, int n){

    for(int i = 0; i < n; i++){
        vector<int> vert;
        adj_list.push_back(vert);
    }
}


void add_edge(vector<vector<int>> &adj_list, int from, int to) {

    adj_list[from].push_back(to);
}


void sort_inner_vectors(vector<vector<int>> &adj_list){
    
    for(int i = 0; i < adj_list.size(); i++){
        sort(adj_list[i].begin(), adj_list[i].end());
    }
}


int main() {
  
    int n, m, a, b;
    cin >> n;
    cin >> m;

    vector<vector<int>> adj_list;
    add_verts(adj_list, n);

    for(int i = 0; i < m; i++){

        cin >> a >> b;
        add_edge(adj_list, a, b);
    }

    sort_inner_vectors(adj_list);
    print_adj_list(adj_list);
}