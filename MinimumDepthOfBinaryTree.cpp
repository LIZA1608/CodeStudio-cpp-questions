/*https://www.codingninjas.com/codestudio/problems/minimum-depth-in-a-binary-tree_696332?leftPanelTab=0*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
    
    template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int minDepth(TreeNode<int>* root)
{
    if(root==NULL){
        return 0;
    }
    int x=minDepth(root->left);
    int y=minDepth(root->right);
    if(x==0 || y==0){
        return x+y+1;
    }
    else{
        return min(x,y)+1;
    }
 
}
