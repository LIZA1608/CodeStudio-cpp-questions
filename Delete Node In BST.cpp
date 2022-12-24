/*https://www.codingninjas.com/codestudio/problems/delete-node-in-bst_920381?leftPanelTab=0*/


#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
BinaryTreeNode<int>* findMin(BinaryTreeNode<int>* root){
    BinaryTreeNode<int>* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key){
    // Write your code here.
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
      if(root->left==NULL && root->right==NULL){
          delete root;
          return NULL;
      }  
      if(root->left !=NULL && root->right==NULL){
          BinaryTreeNode<int>* temp=root->left;
          root->left=NULL;
          delete root;
          return temp;
      }  
      if(root->left==NULL && root->right!=NULL){
          BinaryTreeNode<int>* temp=root->right;
          root->right=NULL;
          delete root;
          return temp;
      }  
        if(root->left!=NULL && root->right!=NULL){
            int mini=findMin(root->right)->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
    }
    else if(root->data<key){
        root->right=deleteNode(root->right,key);
        return root;
    }
    else{
        root->left=deleteNode(root->left,key);
        return root;
    }
    return root;
}
