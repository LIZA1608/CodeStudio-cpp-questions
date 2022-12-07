/*https://www.codingninjas.com/codestudio/problems/identical-trees_799364?leftPanelTab=0*/

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->data!=root2->data!=NULL){
        return false;
    }
    if(identicalTrees(root1->left,root2->left)==false || identicalTrees(root1->right,root2->right)==false){
        return false;
    }
    return true;
}
