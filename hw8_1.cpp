/*
* HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/binary-tree-4/submissions/code/1317331431
* Title: hw8_1.cpp
* Abstract: This code add functions to a binary tree.
* Author: Paul Whipp
* ID: 1222
* Date: 10/29/2019
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

// Node from https://repl.it/@YBYUN/InorderTraversal
struct Node {

    // Data part for a node.
    int data;
    Node* left;
    Node* right;

    // Constructor for a new node.
    Node(int d) {

        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// append modified from https://www.geeksforgeeks.org/
Node * append(Node * root, int key) {
        
    if(!root) {

        return new Node(key);
    }

    queue<Node *> q;
    q.push(root);
    Node * temp;

    // Do level order traversal until we find
    // an empty place.
    while (!q.empty()) {

        temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(key);
            return root;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(key);
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}

// inorder from https://repl.it/@YBYUN/InorderTraversal
void inorder(Node * root) {

    if(root) {

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}



void preorder(Node* root) {

    if(root) {

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {

    if(root) {

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

queue<int> buildInOrderQ(Node * temp, queue<int> &q) {

    if(temp) {
        q = buildInOrderQ(temp->left, q);
        q.emplace(temp->data);
        q = buildInOrderQ(temp->right, q);
    }

    return q;
}

void isBST(Node * temp) {

    queue<int> q;
    q = buildInOrderQ(temp, q);

    int prev = q.front();
    int curr;
    q.pop();

    while(!q.empty()) {

        curr = q.front();
        q.pop();

        if(prev > curr) {

            cout << "false" << endl;
            return;
        }

        prev = curr;
    }

    cout << "true" << endl;
}

// maxDepth modified from https://geeksforgeeks.com
int maxDepth(Node * root) {

    if (root == NULL) {
        return -1;

    } else {

        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        if(lDepth >= rDepth) {

            return lDepth + 1;
        } else {

            return rDepth + 1;
        }
    }
}

void height(Node* root) {

    cout << maxDepth(root) << endl;
}

void initStringVal(unordered_map<string, int> & sv) {

    sv["append"] = 1;
    sv["isBST"] = 2;
    sv["preOrder"] = 3;
    sv["inOrder"] = 4;
    sv["postOrder"] = 5;
    sv["height"] = 6;
}

Node * processCommands(string command,
                     unordered_map<string, int> & sv,
                     Node * root) {

    switch(sv[command]){

        case 1:
            int temp;
            cin >> temp;
            root = append(root, temp);
            break;
        case 2:
            isBST(root);
            break;
        case 3:
            preorder(root);
            cout << endl;
            break;
        case 4:
            inorder(root);
            cout << endl;
            break;
        case 5:
            postorder(root);
            cout << endl;
            break;
        case 6:
            height(root);
            break;
        default:
            // Invalid input
            break;
    }
    
    return root;
}

int main() {

    int n;
    cin >> n;

    // get root
    int temp;
    Node * root = nullptr;

    // get remaining nodes, add to tree
    for(int i = 0; i < n; i++) {

        cin >> temp;
        root = append(root, temp);
    }

    // initialize string conversion
    unordered_map<string, int> stringVal;
    initStringVal(stringVal);


    int numCommands;
    cin >> numCommands;
    string command;
    for(int i = 0; i < numCommands; i++) {

        cin >> command;
        root = processCommands(command, stringVal, root);
    }

    return 0;
}