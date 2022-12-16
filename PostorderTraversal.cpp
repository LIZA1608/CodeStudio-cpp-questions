/*https://www.codingninjas.com/codestudio/problems/postorder-traversal_3839614?leftPanelTab=0*/

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    getPostOrderTraversal(root->left);
        getPostOrderTraversal(root->right);
cout<<root->data<<" ";
    return ans;
}
