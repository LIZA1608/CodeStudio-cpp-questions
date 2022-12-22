/*https://www.codingninjas.com/codestudio/problems/flatten-binary-tree-to-linked-list_1112615?leftPanelTab=0*/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr=root;
    while(curr!=NULL){
        if(curr->left){
            TreeNode<int> *pred=curr->left;
            while(pred->right){
                pred=pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    return root;
}
