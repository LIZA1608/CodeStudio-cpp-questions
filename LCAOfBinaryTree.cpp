/*https://www.codingninjas.com/codestudio/problems/lca-of-binary-tree_920541?leftPanelTab=0*/


#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==NULL){
        return  -1;
    }
    if(root->data==x || root->data==y){
        return root->data;
    }
    int leftans=lowestCommonAncestor(root->left,x,y);
    int rightans=lowestCommonAncestor(root->right,x,y);
    if(leftans!= -1 && rightans!=-1){
        return root->data;
    }
    else if(leftans!=-1 && rightans==-1){
        return leftans;
    }
    else if(leftans==-1 && rightans!=-1){
        return rightans;
    }
    else{
        return -1;
    }
}
