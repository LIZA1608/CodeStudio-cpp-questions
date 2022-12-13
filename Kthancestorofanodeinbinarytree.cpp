/*https://www.codingninjas.com/codestudio/problems/kth-ancestor-of-a-node-in-binary-tree_842561?leftPanelTab=0*/

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
BinaryTreeNode<int>*solve(BinaryTreeNode<int>* root,int node,int &k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    BinaryTreeNode<int>* leftans=solve(root->left,node,k);
    BinaryTreeNode<int>* rightans=solve(root->right,node,k);
    if(leftans!=NULL && rightans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans==NULL && rightans!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    // Write your code here.
    BinaryTreeNode<int>* ans=solve(root,targetNodeVal,k);
    if(ans==NULL || ans->data==targetNodeVal){
        return -1;
    }
    return ans->data;
}
