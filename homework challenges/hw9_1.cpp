/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw9/challenges/max-heap-1-2/submissions/code/1317581996
* Title: hw9_1.cpp
* Abstract: This program takes input (data and 
*           commands) from a user to perform heap 
*           operations. 
* Author: Paul Whipp
* ID: 1222
* Date: 11/8/2019
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void add_input_to_heap(vector<int> &heap, int n) {

    int temp;
    for(int i = 0; i < n; i++) {

        cin >> temp;
        heap.push_back(temp);
    }
}

int right_child_of_idx(int i) {

    return (i * 2) + 1;
}

int left_child_of_idx(int i) {
    
    return i * 2;
}

bool valid_parent(vector<int> &heap, int i) {

    if( left_child_of_idx(i) < heap.size() &&
        heap[left_child_of_idx(i)] > heap[i]) {
        
        return false;
    }

    if( right_child_of_idx(i) < heap.size() &&
        heap[right_child_of_idx(i)] > heap[i]) {
    
        return false;
    }

    return true;
}

bool is_heap(vector<int> &heap) {

    int last_parent = heap.size() / 2;
    for(int i = last_parent; i > 0; i--) {

        if( !valid_parent(heap, i) ) return false;
    }

    return true;
}

void display_heap(vector<int> &heap) {

    for(int i = 1; i < heap.size(); i++) {

        cout << heap[i] << " ";
    }

    cout << endl;
}

void display_max(vector<int> &heap) {

    cout << heap[1] << endl;
}

void bubble_down(int i, vector<int> &heap) {

    int right, left, right_idx, left_idx;

    while(!valid_parent(heap, i)) {

        right_idx = right_child_of_idx(i);
        left_idx = left_child_of_idx(i);

        if(right_idx > heap.size()) right_idx = 0;
        if(left_idx > heap.size()) left_idx = 0;

        right = heap[right_idx];
        left = heap[left_idx];

        if(left > right) {

            heap[left_idx] = heap[i];
            heap[i] = left;
            i = left_idx;

        } else {

            heap[right_idx] = heap[i];
            heap[i] = right;
            i = right_idx;
        }
    }
}

void heapify(vector<int> &heap) {

    int last_parent = heap.size() / 2;
    for(int i = last_parent; i > 0; i--) {

        bubble_down(i, heap);
    }
}

void insert(int val, vector<int> &heap) {

    heap.push_back(val);
    heapify(heap);
}

void find_delete(int val, vector<int> &heap) {

    int i = 1;
    while(i < heap.size() && heap[i] != val) i++;

    // if value not found
    if(i == heap.size()) return;

    // value found
    heap[i] = heap[heap.size() - 1];
    heap.pop_back();

    heapify(heap);
}

void delete_max(vector<int> &heap) {

    // check if heap is empty
    if(heap.size() < 2) return;

    heap[1] = heap[heap.size() - 1];
    heap.pop_back();

    heapify(heap);
}

void initStringVal(unordered_map<string, int> & sv) {

    sv["displayMax"] = 1;
    sv["insert"] = 2;
    sv["deleteMax"] = 3;
    sv["delete"] = 4;
    sv["display"] = 5;
}

void processCommand(string command,
                     unordered_map<string, int> & sv,
                     vector<int> &heap) {

    int temp;
    switch(sv[command]){

        case 1:
            display_max(heap);
            break;
        case 2:
            cin >> temp;
            insert(temp, heap);
            break;
        case 3:
            delete_max(heap);
            break;
        case 4:
            cin >> temp;
            find_delete(temp, heap);
            break;
        case 5:
            display_heap(heap);
            break;
        default:
            // Invalid input
            break;
    }
}

int main() {

    int n;
    cin >> n;

    // process input
    vector<int> heap;
    heap.push_back(-1); // 0 index will not be used

    add_input_to_heap(heap, n);
    
    // test if already heapified
    if(is_heap(heap)) {
        cout << "This is a heap." << endl;
    
    } else {

        cout << "This is NOT a heap." << endl;
        heapify(heap);
    }

    // initialize string conversion
    unordered_map<string, int> stringVal;
    initStringVal(stringVal);


    int numCommands;
    cin >> numCommands;
    string command;
    for(int i = 0; i < numCommands; i++) {

        cin >> command;
        processCommand(command, stringVal, heap);
    }

    return 0;
}