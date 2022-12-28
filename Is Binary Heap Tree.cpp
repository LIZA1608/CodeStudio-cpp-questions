
/*https://www.codingninjas.com/codestudio/problems/is-binary-heap-tree_893136?leftPanelTab=0*/

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
}
bool isCBT(BinaryTreeNode<int>* root,int index,int &totalCount){
    if(root==NULL){
        return true;
    }
    if(index>=totalCount){
        return false;
    }
    else{
        bool left=isCBT(root->left,2*index+1,totalCount);
        bool right=isCBT(root->right,2*index+2,totalCount);
        return left &&right;
    }
}
bool isMaxOrder(BinaryTreeNode<int>* root){
    if(root->left ==NULL && root->right==NULL){
        return  true;
    }
    if(root->right==NULL){
        return (root->data>root->left->data);
    }
    else{
        bool left=isMaxOrder(root->left);
        bool right=isMaxOrder(root->right);
        return (left && right &&(root->data >=root->left->data && 
                 root->data>= root->right->data));
    }
}
bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    int totalCount=countNodes(root);
    int index=0;
    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true;
    }
    else{
        return false;
    }
}
