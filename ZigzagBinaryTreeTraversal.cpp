
/*https://www.codingninjas.com/codestudio/problems/zigzag-binary-tree-traversal_920532?leftPanelTab=0*/

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> zigzagTreeTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    bool lefttoright=true;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>a(size);
        for(int i=0;i<size;i++){
            TreeNode<int>* frontNode=q.front();
            q.pop();
            int index;
            if(lefttoright){
                index=i;
            }
            else{
                index=size-i-1;
            }
            a[index]=frontNode->data;
            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        lefttoright=!lefttoright;
        for(auto i:a){
            ans.push_back(i);
        }
    }
    return ans;
}
