/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/matching-form/submissions/code/1316443984
* Title: hw4_2.cpp
* Abstract: This program checks input against a simple syntax.
* Author: Paul Whipp
* ID: 1222 
* Date: 09/21/2019
*/

#include <iostream>
#include <stack>

using namespace std;

int main() {

    int inp_char;
    int temp;
    stack<int> stck;

    inp_char = cin.get();

    while(inp_char != '\n') {

        // opening symbol
        if(inp_char == '{' || inp_char == '(' || inp_char == '[') {
            
            stck.push(inp_char);
        
        // closing symbol
        } else {

            //get opening symbol, convert
            if(stck.size() != 0) {

                temp = stck.top();
                stck.pop();
            
            } else {

                cout << "FALSE" << endl;
                return 0;
            }
            

            if(temp == '('){
                temp++;
            } else {
                temp += 2;
            }

            if(temp != inp_char) {
                cout << "FALSE" << endl;
                return 0;
            }
        }

        inp_char = cin.get();
    }

    if(stck.size() == 0){
        cout << "TRUE" << endl; 
    } else {
        cout << "FALSE" << endl;
    }
    
    return 0;
}