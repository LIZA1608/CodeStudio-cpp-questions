/*https://www.codingninjas.com/codestudio/problems/convert-binary-tree-to-mirror-tree_873140?leftPanelTab=0*/


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

void mirrorTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root ==NULL){
        return;
    }
  mirrorTree(root->left);
  mirrorTree(root->right);
  BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
