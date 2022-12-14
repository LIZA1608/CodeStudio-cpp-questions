/*https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118521/offering/1380977?leftPanelTab=0*/


/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    queue<TreeNode<int>* >q;
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* front=q.front();
        q.pop();
        ans.push_back(front->val);
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
