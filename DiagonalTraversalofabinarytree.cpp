/*https://www.codingninjas.com/codestudio/problems/diagonal-traversal-of-a-binary-tree_920477?leftPanelTab=0*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:
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

vector<int> diagonalTraversal(TreeNode<int> *root) {
    // Write your code here.
    vector<int>ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            TreeNode<int> *temp=q.front();
            q.pop();
            while(temp){
                ans.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                temp=temp->right;
            }
        }
    }
    return ans;
}
