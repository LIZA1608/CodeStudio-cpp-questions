/*https://www.codingninjas.com/codestudio/problems/construct-a-binary-tree-from-preorder-and-inorder-traversal_920539?leftPanelTab=0*/

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
int findpos(vector<int>in,int curr,int n){
    for(int i=0;i<n;i++){
        if(in[i]==curr){
            return i;
        }
    }
    return -1;
}
TreeNode<int>*solve(vector<int>pre,vector<int>in,int &idx,int inorderstart,int inorderend,int n){
    if(inorderend>n || inorderstart>inorderend){
        return NULL;
    }
    int curr=pre[idx];
    idx++;
    TreeNode<int>* root=new TreeNode<int>(curr);
    int pos=findpos(in,curr,n);
    root->left=solve(pre,in,idx,inorderstart,pos-1,n);
    root->right=solve(pre,in,idx,pos+1,inorderend,n);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preorderindex=0;
    TreeNode<int>*ans=solve(preorder,inorder,preorderindex,0,inorder.size()-1,inorder.size());
    return ans;
}
