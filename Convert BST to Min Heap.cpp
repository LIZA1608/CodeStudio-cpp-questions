/*https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0*/

#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void solve(BinaryTreeNode* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
BinaryTreeNode* convert(BinaryTreeNode* root,vector<int>&ans,int &i){
    if(root==NULL){
        return NULL;
    }
   root->data=ans[i++];
    convert(root->left,ans,i);
    convert(root->right,ans,i);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
    vector<int>ans;
    solve(root,ans);
    int i=0;
    convert(root,ans,i);
    return root;
    
}
