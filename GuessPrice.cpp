/*https://www.codingninjas.com/codestudio/problems/guess-price_3211264?leftPanelTab=0*/


#include <bits/stdc++.h> 
/*
Structure of the Node of the BST is :

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/

int findPrice(Node* root)
{
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL){
        return root->data;
    }
    return findPrice(root->left);
}
