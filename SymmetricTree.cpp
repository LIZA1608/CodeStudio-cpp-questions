/*https://www.codingninjas.com/codestudio/problems/tree-symmetricity_630426?leftPanelTab=0*/

/*****************************************************
    Following is the Binary Tree node structure:
    
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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool isMirror(BinaryTreeNode<int>*first,BinaryTreeNode<int>*second){
    if(first==NULL && second==NULL){
        return true;
    }
    if(first==NULL ||second==NULL){
        return false;
    }
    if(first->data!=second->data){
        return false;
    }
    if(isMirror(first->left,second->right)==false|| isMirror(first->right,second->left)==false){
        return false;
    }
    return true;
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    return isMirror(root,root);
}
