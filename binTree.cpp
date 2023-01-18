/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(): val(0), left(nullptr), right(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

Node* root = NULL;
queue<Node*> points;
void insert(int value){
    Node* current = points.front();
    Node* temp = new Node(value);
    if(root == NULL){
        root = temp;
        points.push(temp);
        // cout << temp -> val << endl;
        return;
    }
    if (current -> left == NULL){
        current -> left = temp; 
        points.push(temp);
    } 
    else if (current -> right == NULL) {
        current ->right = temp; 
        points.push(temp);
    }
    else {
        points.pop();
        insert(value);
    }

}

void printN(Node* currNode, int rotate){
    if(currNode == NULL) return;
    if(rotate == 1){
        cout << '/' << endl ;
    }
    else if (rotate == 2){
        cout << '\\' << endl ;
    }
    cout << currNode -> val << endl ;
    printN(currNode -> left, 1);
    printN(currNode -> right, 2);
}

int main()
{
    //points.push(root);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    // cout << root -> val;
    printN(root,0);

}
