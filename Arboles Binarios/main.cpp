#include <iostream>
#include "Menu.h" 
#include <stdlib.h>

int main(){
	menu(); 
	cout << endl;
 	return 0;
}































/*
#include <iostream>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = NULL;
    }
};

// Recursive function to calculate height of given binary tree
int height(Node* root)
{
    // Base case: empty tree has height 0
    if (root == NULL)
        return 0;

    // recur for left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}*/



