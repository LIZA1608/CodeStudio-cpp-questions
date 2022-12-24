/*https://www.codingninjas.com/codestudio/problems/validate-bst_799483?leftPanelTab=0*/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool isBst(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool left=   isBst(root->left,min,root->data);
        bool right=isBst(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBst(root,INT_MIN,INT_MAX);
}
