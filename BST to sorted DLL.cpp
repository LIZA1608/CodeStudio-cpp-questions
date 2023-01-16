/*https://www.codingninjas.com/codestudio/problems/bst-to-sorted-dll_1263694?leftPanelTab=1*/

void convert(TreeNode<int>* root,TreeNode<int>* &head){
    if(root==NULL){
        return ;
    }
    convert(root->right,head);
    root->right=head;
    if(head!=NULL){
    head->left=root;
    }
    head=root;
    convert(root->left,head);
}
TreeNode<int>* bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int>* head=NULL;
    convert(root,head);
    return head;
}
