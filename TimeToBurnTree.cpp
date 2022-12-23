/*https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?leftPanelTab=0*/


#include<bits/stdc++.h>
/************************************************************

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
    };

************************************************************/
BinaryTreeNode<int>*create(BinaryTreeNode<int>* root,int target,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&nodetoparent){
    BinaryTreeNode<int>* res=NULL;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>*front=q.front();
        q.pop();
        if(front->data==target){
            res=front;
        }
        if(front->left){
            nodetoparent[front->left]=front;
            q.push(front->left);
        }
        if(front->right){
            nodetoparent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}
int burntree(BinaryTreeNode<int>*root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&nodetoparent){
    map<BinaryTreeNode<int>*,bool>visited;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        bool flag=0;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>*front=q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag=1;
                q.push(front->left);
                visited[front->left]=1;
            }
            if(front->right && !visited[front->right]){
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            if(nodetoparent[front] && !visited[nodetoparent[front]]){
                flag=1;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]]=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
  
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>nodetoparent;
    BinaryTreeNode<int>*targetNode=create(root,start,nodetoparent);
    int ans=burntree(targetNode,nodetoparent);
    return ans;
}
